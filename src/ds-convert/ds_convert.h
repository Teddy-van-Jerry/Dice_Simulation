/**
 * @brief Dice Simulation Convert Class
 *
 * @date 2021-12-12
 * @author Teddy van Jerry
 */

#ifndef DS_CONVERT_H
#define DS_CONVERT_H
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
     * @brief Style the converted cpp file using astyle.
     * @return status
     * @retval true The conversion succeeds.
     * @retval false The conversion fails.
     */
    bool style();

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
    QString sourceFile_; /**< Source file to convert (.ds, .ds-cpp). */

    QString destinationFile_; /**< Converted .cpp file. */

    QStringList lines_; /**< Source lines. */

    bool debug_ = false; /**< Debug option. */

    bool mainConverted = false; /** Tag indicating whether mainConvert has been called. */

    QVector<QStringPair> blockDefPairs {
        {"#DS_BEGIN_GLOBAL" , "#DS_END_GLOBAL"},
        {"#DS_BEGIN_DICE"   , "#DS_END_DICE"},
        {"#DS_BEGIN_TASK"   , "#DS_END_TASK"},
        {"#DS_BEGIN_CPP"    , "#DS_END_CPP"},
        {"#DS_BEGIN_PROCESS", "#DS_END_PROCESS"}
    };

    /**
     * @brief Initialize the converted file.
     * @return status
     * @retval true no error
     * @retval false there exists error
     */
    bool initConvert();

    /**
     * @brief Add int main() and floor settings
     * @details This will check whether mainConvert() has been called before,
     *          so this function can be called when there is a possibility.
     * @return status
     * @retval true no error
     * @retval false there exists error
     */
    bool mainConvert();

    /**
     * @brief Read source file and set lines_.
     * @return status
     * @retval true no error
     * @retval false there exists error
     */
    bool readFileAll();

    /**
     * @brief Write line into destination file.
     * @param line text of the line
     * @return status
     * @retval true no error
     * @retval false there exists error
     */
    bool writeLine(const QString& line) const;

    /**
     * @brief Write lines into destination file.
     * @param lines text lines
     * @return status
     * @retval true no error
     * @retval false there exists error
     */
    bool writeLines(const QStringList& lines) const;

    /**
     * @brief Convert the defination of variable from ds to cpp.
     * @param type C++ data type
     * @param varName variable name
     * @param value value of the variable
     * @return the string of the cpp code
     */
    QString convertVarDef(QString type, QString varName, const QString& value) const;

    /**
     * @brief Remove comments in lines_.
     * @return status
     * @retval true no error
     * @retval false there exists error
     */
    bool removeComments();

    /**
     * @brief ensure the bracket at both sides (i.e. add '(' or ')' if there isn't)
     * @param str the string to ensure
     */
    void ensureBacket(QString& str);

    /**
     * @brief Convert the DS Block.
     * @param blockType index of blockDefPairs
     * @param begin_i line number of start block symbol (#DS_BEGIN_XXX)
     * @param end_i line number of end block symbol (#DS_END_XXX)
     * @return status
     * @retval true no error
     * @retval false there exists error
     */
    bool convertDSBlock(int blockType, int begin_i, int end_i);

    /**
     * @brief Convert DS GLOBAL.
     * @param begin_i line number of start block symbol (#DS_BEGIN_GLOBAL)
     * @param end_i line number of end block symbol (#DS_END_GLOBAL)
     * @return status
     * @retval true no error
     * @retval false there exists error
     */
    bool convert_DS_GLOBAL(int begin_i, int end_i);

    /**
     * @brief Convert DS DICE.
     * @param begin_i line number of start block symbol (#DS_BEGIN_DICE)
     * @param end_i line number of end block symbol (#DS_END_DICE)
     * @return status
     * @retval true no error
     * @retval false there exists error
     */
    bool convert_DS_DICE(int begin_i, int end_i);

    /**
     * @brief Convert DS CPP.
     * @param begin_i line number of start block symbol (#DS_BEGIN_CPP)
     * @param end_i line number of end block symbol (#DS_END_CPP)
     * @return status
     * @retval true no error
     * @retval false there exists error
     */
    bool convert_DS_CPP(int begin_i, int end_i);

    /**
     * @brief Convert DS PROCESS.
     * @param begin_i line number of start block symbol (#DS_BEGIN_PROCESS)
     * @param end_i line number of end block symbol (#DS_END_PROCESS)
     * @return status
     * @retval true no error
     * @retval false there exists error
     */
    bool convert_DS_PROCESS(int begin_i, int end_i);

    /**
     * @brief Convert DS TASK CALL in DS PROCESS
     * @param task the task being called
     * @param begin_i line number of start block symbol (```)
     * @param end_i line number of end block symbol (```!)
     * @return status
     * @retval true no error
     * @retval false there exists error
     */
    bool convert_DS_CALL_TASK(QString task, int begin_i, int end_i);

};

#endif // DS_CONVERT_H
