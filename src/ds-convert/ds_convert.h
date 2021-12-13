/**
 * @brief Dice Simulation Convert Class
 *
 * @date 2021-12-12
 * @author Teddy van Jerry
 */

#ifndef DS_CONVERT_H
#define DS_CONVERT_H
#include <QFileInfo>
#include <QTextStream>
#include "global.h"

class DS_Convert
{
public:
    DS_Convert();

    /**
     * @brief Constructor for converting ds file to standard cpp file.
     * @param sourceFile source .ds or .ds-cpp file
     * @param destinationFile converted .cpp file
     */
    DS_Convert(QString sourceFile, QString destinationFile);

    /**
     * @brief Start converting.
     * @return status
     * @retval true The conversion succeeds.
     * @retval false The conversion fails.
     */
    bool convert();

    /**
     * @brief Set convert source and destination files.
     * @param sourceFile source .ds or .ds-cpp file
     * @param destinationFile converted .cpp file
     */
    void setFiles(QString sourceFile, QString destinationFile);

    /**
     * @brief Set the debug option.
     * @param debug Debug option (true or false).
     */
    void setDebug(bool debug);

private:
    QString sourceFile_; /**< Source file to convert (.ds, .ds-cpp) */

    QString destinationFile_; /**< Converted .cpp file */

    QStringList lines_; /**< Source lines */

    bool debug_ = false; /**< Debug option */

    QVector<QStringPair> blockDefPairs {
        {"DS_BEGIN_GLOBAL" , "DS_END_GLOBAL"},
        {"DS_BEGIN_DICE"   , "DS_END_DICE"},
        {"DS_BEGIN_TASK"   , "DS_END_TASK"},
        {"DS_BEGIN_CPP"    , "DS_END_CPP"},
        {"DS_BEGIN_PROCESS", "DS_END_PROCESS"}
    };

    /**
     * @brief read source file and set lines_.
     */
    void readFileAll();

    /**
     * @brief write line into destination file.
     * @param line text of the line
     */
    void writeLine(const QString& line) const;

    /**
     * @brief write lines into destination file.
     * @param lines text lines
     */
    void writeLines(const QStringList& lines) const;

    /**
     * @brief Remove comments in lines_.
     * @return status
     * @retval true no error
     * @retval false there exists error
     */
    bool removeComments();

};

#endif // DS_CONVERT_H
