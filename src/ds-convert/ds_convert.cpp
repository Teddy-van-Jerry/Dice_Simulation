#include "ds_convert.h"

DS_Convert::DS_Convert() { }

DS_Convert::DS_Convert(QString sourceFile, QString destinationFile)
    : sourceFile_(sourceFile), destinationFile_(destinationFile) { }

bool DS_Convert::convert() {
    initConvert();
    readFileAll();
    if (lines_.empty()) return true;
    // qDebug() << lines_; // debug
    int i = 0; // line number index, from 0 to lines_.size() - 1
    while (i < lines_.size()) {
        QString line_simplified = lines_.at(i).simplified();
        // Skip empty line.
        if (!line_simplified.isEmpty()) {
            // If contents are not inside # block, just ignore them.
            int index = 0; // index of the block type in blockDefPairs
            for (; index != blockDefPairs.size() && line_simplified != blockDefPairs.at(index).at(0); index++);
            if (index < blockDefPairs.size()) {
                int j = i + 1; // line number of the end block
                for (; j < lines_.size(); j++) {
                    QString line_simplified = lines_.at(j).simplified();
                    if (line_simplified == blockDefPairs.at(index).at(1)) break; // find match
                }
                if (j > lines_.size()) {
                    qDebug() << "ERROR: unclosed DS block";
                    return false;
                }
                if (convertDSBlock(index, i, j)) i = j;
                else return false; // convert the block from line i to j
            }
        }
        i++;
    }
    style();
    return true;
}

bool DS_Convert::style() {
    QProcess* styleProcess = new QProcess;
    QFileInfo destinationFileInfo(destinationFile_);
    styleProcess->setWorkingDirectory(QCoreApplication::applicationDirPath());
    QStringList args;
    args << "--style=java" << "-n" << destinationFileInfo.absoluteFilePath();
    styleProcess->start("astyle", args);
    styleProcess->waitForFinished();
    return true;
}

void DS_Convert::setFiles(QString sourceFile, QString destinationFile) {
    sourceFile_      = sourceFile;
    destinationFile_ = destinationFile;
}

void DS_Convert::setDebug(bool debug) {
    debug_ = debug;
}

bool DS_Convert::initConvert() {
    QFile f(destinationFile_);
    if (f.open(QIODevice::WriteOnly)) {
        QTextStream out(&f);
        out << "// Converted by Dice Simulation " << __DS_VERSION_STR__
            << " at " << QDateTime::currentDateTimeUtc().toString("yyyy-MM-dd hh:mm:ss UTC") << ".\n"
            << "// Website: https://dice.teddy-van-jerry.org\n"
            << "// GitHub Repo: https://github.com/Teddy-van-Jerry/Dice_Simulation\n" << Qt::endl;
        f.close();
        return true;
    } else {
        qDebug() << "Cannot write file " << destinationFile_ << Qt::endl;
        return false;
    }
}

bool DS_Convert::mainConvert() {
    if (mainConverted) return true;
    QStringList converted;
    converted << "\nint main(int argc, char* argv[]) {"
              << "\t// ====== floor ====== //"
              << "PhysicsCommon physicsCommon;\nPhysicsWorld* world = physicsCommon.createPhysicsWorld();"
              << "world->setGravity(Vector3(0, -" + gravityName + ", 0));"
              << "BoxShape* floor_shape = physicsCommon.createBoxShape(Vector3(1000000, 1, 1000000));"
              << "RigidBody* floor = world->createRigidBody(Transform(Vector3(0, -1, 0), Quaternion::identity()));"
              << "floor->setType(BodyType::STATIC);"
              << "floor->addCollider(floor_shape, Transform::identity());\n";
    mainConverted = true;
    return writeLines(converted);
}

bool DS_Convert::readFileAll() {
    QFile f(sourceFile_);
    if (f.open(QIODevice::ReadOnly)) {
        QTextStream in(&f);
        lines_.clear();
        while (!in.atEnd()) {
            QString line = in.readLine();
            lines_.push_back(line);
        }
        f.close();
    } else {
        qDebug() << "Cannot open file " << sourceFile_ << Qt::endl;
        return false;
    }
    removeComments(); // replace comments texts into spaces
    return true;
}

bool DS_Convert::writeLine(const QString& line) const {
    QFile f(destinationFile_);
    if (f.open(QIODevice::WriteOnly | QIODevice::Append)) {
        QTextStream out(&f);
        out << line << Qt::endl;
        f.close();
        return true;
    } else {
        qDebug() << "Cannot write file " << destinationFile_ << Qt::endl;
        return false;
    }
}

bool DS_Convert::writeLines(const QStringList& lines) const {
    QFile f(destinationFile_);
    if (f.open(QIODevice::WriteOnly | QIODevice::Append)) {
        QTextStream out(&f);
        for (const auto& line : lines) out << line << Qt::endl;
        f.close();
        return true;
    } else {
        qDebug() << "Cannot write file " << destinationFile_ << Qt::endl;
        return false;
    }
}

QString DS_Convert::convertVarDef(QString type, QString varName, const QString& value) const {
    return type + " " + varName + " = " + value + ";";
}

bool DS_Convert::removeComments() {
    int comment_row = 0; // the row that "/*" occurs
    int current_row = 0; // the current line number
    for (auto& line : lines_) {
        current_row++;
        if (line.length() < 2) {
            // no chance of being the beginning or end of comments
            // If inside multi-line comments, just clear it out.
            // But here ensures that it has length 1.
            if (comment_row) line.clear();
            line.push_back(' ');
            continue;
        }
        for (auto i = 0; i != line.length(); i++) {
            if (comment_row) {
                if (i + 1 == line.length()) {
                    line[i] = ' ';
                    break;
                }
                // finding the matching "*/"
                if (line[i] == '*' && line[i + 1] == '/') {
                    line[i] = line[i + 1] = ' ';
                    i++;
                    comment_row = 0;
                    continue;
                } else {
                    line[i] = ' ';
                }
            } else {
                // check if it is the beginning of comments
                if (i + 1 >= line.length()) break;
                if (line[i] != '/') continue;
                if (line[i + 1] == '/') {
                    // single-line comments
                    line = line.left(i); // from 0 to i - 1
                    break;
                } else if (line[i + 1] == '*') {
                    // multi-line comments
                    comment_row = current_row;
                    line[i] = line[i + 1] = ' ';
                }
            }
        }
    }
    // If comment_row is not set to 0,
    // there are unfinshed comments.
    if (comment_row) {
        // ERROR: Unfinished Comments
    }
    return !comment_row;
}

void DS_Convert::ensureBracket(QString &str) {
    str = str.trimmed();
    if (str.isEmpty()) str = "()";
    else {
        if (str.at(0) != '(') str.insert(0, '(');
        if (*(str.end() - 1) != ')') str.append(')');
    }
}

bool DS_Convert::convertDSBlock(int blockType, int begin_i, int end_i) {
    switch (blockType) {
    case 0:
        return convert_DS_GLOBAL(begin_i, end_i);
    case 1:
        mainConvert();
        return convert_DS_DICE(begin_i, end_i);
    case 3:
        return convert_DS_CPP(begin_i, end_i);
    case 4:
        mainConvert();
        return convert_DS_PROCESS(begin_i, end_i);
    default:
        return false;
    }
}

bool DS_Convert::convert_DS_GLOBAL(int begin_i, int end_i) {
    QStringList converted;
    QStringList includeConverted = {"#include \"ds_core.ds-h\""};
    int i = begin_i; // line number
    while (++i != end_i) {
        QString line = lines_.at(i);
        // Find the first occurence of the sybols
        // to avoid the problem of user employing these symbols in value defination.
        int _1 = line.indexOf(':'); // the division symbol after variable name
        if (_1 == -1) {
            // does not find ':', just skip this line
            // maybe WARNING or ERROR in the future
            // This should not trigger an error because this line can be empty.
            continue;
        }
        QString fieldName = line.left(_1).simplified().remove(QChar('\"')).toLower();
        QString varName = fieldName;
        QString value = line.mid(_1 + 1).trimmed();
        int _2 = line.indexOf('[', _1);
        // qDebug() << line.mid(_1 + 1, _2 - _1 - 1).trimmed();
        if (line.mid(_1 + 1, _2 - _1 - 1).trimmed().isEmpty()) {
            // This is indeed the start symbol of variable name (optional).
            int _3 = line.indexOf(']', _2); // the end symbol of variable name.
            if (_3 == -1) {
                qDebug() << "ERROR: unclosed '['";
                return false;
            }
            varName = line.mid(_2 + 1, _3 - _2 - 1).simplified().remove(QChar('\"'));
            // qDebug() << varName;
            value = line.mid(_3 + 1).trimmed();
        }

        // qDebug() << fieldName;

        if (fieldName == "gravity") {
            converted.append("double " + varName + " = " + value + ";");
            gravityName = varName;
        } else if (fieldName == "include") {
            QStringList includeStatements = value.split(",;", Qt::SkipEmptyParts);
            for (const auto& s : includeStatements) includeConverted.append("#include " + s);
        } else if (fieldName == "version") {
            converted.append("const char* " + varName + " = " + value + ";");
        } else if (fieldName == "random") {
            converted.append("DSRandom " + value.remove(QChar('\"')) + "; // random engine");
        }
    }
    if (!writeLines(includeConverted << "using namespace ds;\n")) return false;
    return (writeLines(converted << ""));
}

bool DS_Convert::convert_DS_DICE(int begin_i, int end_i) {
    QStringList labels; // propertity labels of dice
    QStringList values; // values in for labels (i.e. after ':')
    int i = begin_i;
    while (++i < end_i) {
        QString trimmedLine = lines_.at(i).trimmed();
        int k = trimmedLine.indexOf(':');
        if (k != -1) {
            labels.append(trimmedLine.left(k).remove(QChar('\"')).simplified().toLower());
            if (!labels.isEmpty()) values.append(trimmedLine.mid(k + 1).trimmed());
        }
    }
    // qDebug() << labels;
    // qDebug() << values;
    QStringList converted;
    QString _name, _type, _size_a, _size_b, _size_c, _size_r, _size_h, _cylinder_sides, _position, _orientation, _velocity,
            _angular_velocity, _friction, _bounciness, _damping, _angular_damping, _mass, _density;
    for (int m = 0; m != labels.size(); m++) {
        QString label = labels.at(m);
        QString value = values.at(m);
        if      (label == "name")             _name             = value;
        else if (label == "type")             _type             = value;
        else if (label == "size_a")           _size_a           = value;
        else if (label == "size_b")           _size_b           = value;
        else if (label == "size_c")           _size_c           = value;
        else if (label == "size_r")           _size_r           = value;
        else if (label == "size_h")           _size_h           = value;
        else if (label == "cylinder_sides")   _cylinder_sides   = value;
        else if (label == "position")         _position         = value;
        else if (label == "orientation")      _orientation      = value;
        else if (label == "velocity")         _velocity         = value;
        else if (label == "angular_velocity") _angular_velocity = value;
        else if (label == "friction")         _friction         = value;
        else if (label == "bounciness")       _bounciness       = value;
        else if (label == "damping")          _damping          = value;
        else if (label == "angular_damping")  _angular_damping  = value;
        else if (label == "mass")             _mass             = value;
        else if (label == "density")          _density          = value;
    }
    ensureBracket(_position);
    ensureBracket(_orientation);
    ensureBracket(_velocity);
    ensureBracket(_angular_velocity);
    _name.remove(QChar('\"'));
    _type.remove(QChar('\"'));
    if (_name.isEmpty()) {
        // WARNING: dice name undefined
        // just ignore this block
        return true;
    }
    converted.append("\t// ====== DS DICE: " + _name + " ====== //");
    if (_position.length() == 2) _position = "(0, 1, 0)"; // one metre above the ground
    if (_type == "box") {
        if (_size_a.isEmpty() || _size_b.isEmpty() || _size_c.isEmpty()) {
            qDebug() << "WARNING: size of the box dice is not defined";
            // just ignore this block
            return true;
        }
        converted << "RigidBody* " + _name + "_body = world->createRigidBody(Transform(Vector3" + _position + ", normalQuaternion" + _orientation + "));"
                  << "BoxShape* " + _name + "_shape = physicsCommon.createBoxShape(Vector(" + _size_a + ", "  + _size_b + ", " + _size_c + "));"
                  << _name + "_body->addCollider(" + _name + "_shape, Transform::identity());";
        if (_velocity.length() > 2) converted.append(_name + "_body->setLinearVelocity(Vector3" + _velocity + ");");
        if (_angular_velocity.length() > 2) converted.append(_name + "_body->setAngularVelocity(Vector3" + _angular_velocity + ");");
        if (!_damping.isEmpty()) converted.append(_name + "_body->setLinearDamping(" + _damping + ");");
        if (!_angular_damping.isEmpty()) converted.append(_name + "_body->setAngularDamping(" + _angular_damping + ");");
        if (!_bounciness.isEmpty()) converted.append(_name + "_body->getCollider(0)->getMaterial().setBounciness(" + _bounciness + ");");
        if (!_friction.isEmpty()) converted.append(_name + "_body->getCollider(0)->getMaterial().setFrictionCoefficient(" + _friction + ");");
        // mass and density will not make a difference currently.
    } else if (_type == "cylinder") {
        if (_size_r.isEmpty() || _size_r.isEmpty()) {
            qDebug() << "WARNING: size of the cylinder dice is not defined";
            // just ignore this block
            return true;
        }
        if (!_cylinder_sides.isEmpty()) _cylinder_sides = "1000";
        converted << "RigidBody* " + _name + "_body = world->createRigidBody(Transform(Vector3" + _position + ", normalQuaternion" + _orientation + "));"
                  << "const int " + _name + "_sides = " + _cylinder_sides + ";"
                  << "const float " + _name + "_R = " + _size_r + ";"
                  << "const float " + _name + "_H = " + _size_h + ";"
                  << "float " + _name + "_vertices[6 * " + _name + "_sides];"
                  << "for (int i = 0; i != " + _name + "_sides; i++) {"
                  << _name + "_vertices[3 * i] = -" + _name + "_R * std::cos(2 * 3.14159265358979 * i / " + _name + "_sides);"
                  << _name + "_vertices[3 * i + 1] = -" + _name + "_H / 2;"
                  << _name + "_vertices[3 * i + 2] = " + _name + "_R * std::sin(2 * 3.14159265358979 * i / " + _name + "_sides);"
                  << _name + "_vertices[3 * (i + " + _name + "_sides)] = " + _name + "_vertices[3 * i];"
                  << _name + "_vertices[3 * (i + " + _name + "_sides) + 1] = " + _name + "_H / 2;"
                  << _name + "_vertices[3 * (i + " + _name + "_sides) + 2] = " + _name + "_vertices[3 * i + 2];}"
                  << "int " + _name + "_indices[6 * " + _name + "_sides];"
                  << "for (int i = 0; i != " + _name + "_sides - 1; i++) {"
                  << _name + "_indices[4 * i    ] = i;"
                  << _name + "_indices[4 * i + 1] = i + 1;"
                  << _name + "_indices[4 * i + 2] = " + _name + "_sides + i + 1;"
                  << _name + "_indices[4 * i + 3] = " + _name + "_sides + i;"
                  << _name + "_indices[4 * " + _name + "_sides + i] = " + _name + "_sides - i - 1;"
                  << _name + "_indices[5 * " + _name + "_sides + i] = " + _name + "_sides + i;}"
                  << _name + "_indices[4 * " + _name + "_sides - 4] = " + _name + "_sides - 1;"
                  << _name + "_indices[4 * " + _name + "_sides - 3] = 0;"
                  << _name + "_indices[4 * " + _name + "_sides - 2] = " + _name + "_sides;"
                  << _name + "_indices[4 * " + _name + "_sides - 1] = 2 * " + _name + "_sides - 1;"
                  << _name + "_indices[5 * " + _name + "_sides - 1] = 0;"
                  << _name + "_indices[6 * " + _name + "_sides - 1] = 2 * " + _name + "_sides - 1;"
                  << "PolygonVertexArray::PolygonFace " + _name + "_polygonFaces[" + _name + "_sides + 2];"
                  << "for (int f = 0; f != " + _name + "_sides; f++) {"
                  << _name + "_polygonFaces[f].indexBase = f * 4;"
                  << _name + "_polygonFaces[f].nbVertices = 4;}"
                  << _name + "_polygonFaces[" + _name +"_sides].indexBase = " + _name + "_sides * 4;"
                  << _name + "_polygonFaces[" + _name +"_sides].nbVertices = " + _name + "_sides;"
                  << _name + "_polygonFaces[" + _name +"_sides + 1].indexBase = " + _name + "_sides * 5;"
                  << _name + "_polygonFaces[" + _name +"_sides + 1].nbVertices = " + _name + "_sides;"
                  << "PolygonVertexArray* " + _name + "_polygonVertexArray = new PolygonVertexArray("
                  << "2 * " + _name + "_sides, " + _name + "_vertices, 3 * sizeof(float), " + _name + "_indices,"
                  << "sizeof(int), " + _name + "_sides + 2, " + _name + "_polygonFaces,"
                  << "PolygonVertexArray::VertexDataType::VERTEX_FLOAT_TYPE, PolygonVertexArray::IndexDataType::INDEX_INTEGER_TYPE);"
                  << "PolyhedronMesh* " + _name + "_polyhedronMesh = physicsCommon.createPolyhedronMesh(" + _name + "_polygonVertexArray);"
                  << "ConvexMeshShape*" + _name + "_shape = physicsCommon.createConvexMeshShape(" + _name + "_polyhedronMesh);"
                  << _name + "_body->addCollider(" + _name + "_shape, Transform::identity());";
        if (_velocity.length() > 2) converted.append(_name + "_body->setLinearVelocity(Vector3" + _velocity + ");");
        if (_angular_velocity.length() > 2) converted.append(_name + "_body->setAngularVelocity(Vector3" + _angular_velocity + ");");
        if (!_damping.isEmpty()) converted.append(_name + "_body->setLinearDamping(" + _damping + ");");
        if (!_angular_damping.isEmpty()) converted.append(_name + "_body->setAngularDamping(" + _angular_damping + ");");
        if (!_bounciness.isEmpty()) converted.append(_name + "_body->getCollider(0)->getMaterial().setBounciness(" + _bounciness + ");");
        if (!_friction.isEmpty()) converted.append(_name + "_body->getCollider(0)->getMaterial().setFrictionCoefficient(" + _friction + ");");
    }
    converted.append("");
    return writeLines(converted);
}

bool DS_Convert::convert_DS_CPP(int begin_i, int end_i) {
    return writeLines(lines_.mid(begin_i + 1, end_i - begin_i - 1) << "");
}

bool DS_Convert::convert_DS_PROCESS(int begin_i, int end_i) {
    QStringList converted;
    int i = begin_i; // line number
    while (++i != end_i) {
        QString trimmedLine = lines_.at(i).trimmed();
        if (trimmedLine.length() > 3 && trimmedLine.left(3) == "```") {
            int j = i + 1;
            for (;j < end_i; j++) {
                QString trimmedLine_ = lines_.at(j).trimmed();
                if (trimmedLine_.length() == 4 && trimmedLine_.left(4) == "```!") break;
            }
            if (j >= end_i) {
                qDebug() << "ERROR: unclosed TASK calling (no ```! for a ```)";
                return false;
            }
            if (trimmedLine.length() == 3) {
                qDebug() << "ERROR: no task name specified";
                return false;
            }
            QString taskName = trimmedLine.mid(3).trimmed();
            if (!writeLines(converted)) return false;
            converted.clear();
            if (!convert_DS_TASK_CALL(taskName, i, j)) return false;
            i = j;
        } else if (trimmedLine == "#DS_BEGIN_DICE") {
            int j = i + 1;
            for (;j < end_i; j++) {
                QString trimmedLine_ = lines_.at(j).trimmed();
                if (trimmedLine_ == "#DS_END_DICE") break;
            }
            if (j >= end_i) {
                qDebug() << "ERROR: unclosed DS TASK block";
                return false;
            }
            if (!writeLines(converted)) return false;
            converted.clear();
            if (!convert_DS_DICE(i, j)) return false;
            i = j;
        } else converted.append(trimmedLine);
    }
    converted.append("return 0;}\n");
    return writeLines(converted);
}

bool DS_Convert::convert_DS_TASK_CALL(QString task, int begin_i, int end_i) {
    taskID++; // increment the DS TASK CALL ID
    QString _ID = QString::number(taskID); // QString of taskID
    // Only built-in tasks are supported in this version.
    QStringList args;   // arguments in task
    QStringList values; // values in task for arguments (i.e. after ':')
    int i = begin_i;
    while (++i < end_i) {
        QString trimmedLine = lines_.at(i).trimmed();
        int k = trimmedLine.indexOf(':');
        if (k != -1) {
            args.append(trimmedLine.left(k).remove(QChar('\"')).simplified().toLower());
            if (!args.isEmpty()) values.append(trimmedLine.mid(k + 1));
        }
    }
    QStringList converted {"\t// ====== DS TASK: " + task + " ====== //"};
    QString _dice, _position, _orientation, _velocity, _angular_velocity, _friction, _bounciness, _damping,
            _angular_damping, _mass, _density, _print, _print_condition, _time_step, _time_limit, _stop_threshold,
            _before_update, _after_update_1, _after_update_2, _after_update_3;
    if (task.trimmed().toLower() == "simu") {
        for (int m = 0; m != args.size(); m++) {
            QString arg = args.at(m);
            QString value = values.at(m);
            if      (arg == "dice")             _dice             = value;
            else if (arg == "position")         _position         = value;
            else if (arg == "orientation")      _orientation      = value;
            else if (arg == "velocity")         _velocity         = value;
            else if (arg == "angular_velocity") _angular_velocity = value;
            else if (arg == "friction")         _friction         = value;
            else if (arg == "bouciness")        _bounciness       = value;
            else if (arg == "damping")          _damping          = value;
            else if (arg == "angular_damping")  _angular_damping  = value;
            else if (arg == "mass")             _mass             = value;
            else if (arg == "density")          _density          = value;
            else if (arg == "print")            _print            = value;
            else if (arg == "print_condition")  _print_condition  = value;
            else if (arg == "time_step")        _time_step        = value;
            else if (arg == "time_limit")       _time_limit       = value;
            else if (arg == "stop_threshold")   _stop_threshold   = value;
            else if (arg == "before_update")    _before_update    = value;
            else if (arg == "after_update_1")   _after_update_1   = value;
            else if (arg == "after_update_2")   _after_update_2   = value;
            else if (arg == "after_update_3")   _after_update_3   = value;
        }
        QString _name = _dice; // alias so I can copy code from convert_DS_Dice
        ensureBracket(_position);
        ensureBracket(_orientation);
        ensureBracket(_velocity);
        ensureBracket(_angular_velocity);
        if (_time_step.isEmpty()) _time_step = "1.0f / 60.0f";
        if (_time_limit.isEmpty()) _time_limit = "300000.0f";
        if (_print_condition.isEmpty()) _print_condition = "true";
        if (_stop_threshold.isEmpty()) _stop_threshold = "1E-8";

        _name.remove(QChar('\"'));
        if (_position.length() > 2) converted.append(_name + "_body->setTransform(Transform(Vector3" + _position + ", " + _name + "_body->getTransform().getOrientation()));");
        if (_orientation.length() > 2) converted.append(_name + "_body->setTransform(Transform(" + _name + "_body->getTransform().getPosition(), normalQuaternion" + _orientation + "));");
        if (_velocity.length() > 2) converted.append(_name + "_body->setLinearVelocity(Vector3" + _velocity + ");");
        if (_angular_velocity.length() > 2) converted.append(_name + "_body->setAngularVelocity(Vector3" + _angular_velocity + ");");
        if (!_damping.isEmpty()) converted.append(_name + "_body->setLinearDamping(" + _damping + ");");
        if (!_angular_damping.isEmpty()) converted.append(_name + "_body->setAngularDamping(" + _angular_damping + ");");
        if (!_bounciness.isEmpty()) converted.append(_name + "_body->getCollider(0)->getMaterial()->setBounciness(" + _bounciness + ");");
        if (!_friction.isEmpty()) converted.append(_name + "_body->getCollider(0)->getMaterial()->setFrictionCoefficient(" + _friction + ");");
        converted << "const float timeStep_" + _ID + " = " + _time_step + ";"
                  << "for (int i = 0; i < int((" + _time_limit + ") / (" + _time_step + ")); i++) {";
        if (!_before_update.isEmpty()) converted << _before_update;
        converted << "world->update(timeStep_" + _ID + ");"
                  << "const Transform& transform = " + _name + "_body->getTransform();"
                  << "const Vector3& position = transform.getPosition();"
                  << "const Vector3& velocity = " + _name + "_body->getLinearVelocity();"
                  << "const Vector3& angular_velocity = " + _name + "_body->getAngularVelocity();"
                  << "const Quaternion& orientation = transform.getOrientation();";
        if (!_after_update_1.isEmpty()) converted << _after_update_1;
        converted << "if (" + _print_condition + ") {";
        QStringList printContents = _print.split(',', Qt::SkipEmptyParts);
        for (const auto& label_ : printContents) {
            QString label = label_.trimmed();
            if (label == ";") {
                converted << "std::cout << std::endl;";
            } else if (label == "$position") {
                converted << "std::cout << \"(\" << position.x << \", \" << position.y << \", \" << position.z << \")\";";
            } else if (label == "$velocity") {
                converted << "std::cout << \"(\" << velocity.x << \", \" << velocity.y << \", \" << velocity.z << \")\";";
            } else if (label == "$angular_velocity") {
                converted << "std::cout << \"(\" << angular_velocity.x << \", \" << angular_velocity.y << \", \" << angular_velocity.z << \")\";";
            } else if (label == "$orientation") {
                converted << "std::cout << \"(\" << orientation.x << \", \" << orientation.y << \", \" << orientation.z << \", \" << orientation.w << \")\";";
            } else if (label == "|$velocity|") {
                converted << "std::cout << velocity.length();";
            } else if (label == "|$angular_velocity|") {
                converted << "std::cout << angular_velocity.length();";
            } else {
                converted << "std::cout << " + label + ";";
            }
        }
        converted << "}";
        if (!_after_update_2.isEmpty()) converted << _after_update_2;
        converted << "if (velocity.length() <= " + _stop_threshold + " && angular_velocity.length() <= " + _stop_threshold + ") break;";
        if (!_after_update_3.isEmpty()) converted << _after_update_3;
        converted << "}";

    } else if (task.trimmed().toLower() == "prob") {

    } else {
        // Just ignore
        qDebug() << "WARNING: unsupported TASK name";
    }
    return writeLines(converted << "");
}
