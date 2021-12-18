/**
 * @file ds-compile/ds_compile.h
 * @brief Dice Simulation Compile Class
 *
 * @date 2021-12-17
 * @author Teddy van Jerry
 */

#ifndef DS_COMPILE_H
#define DS_COMPILE_H

#include "global.h"

/**
 * @brief The Dice Simulation Compile class
 * @details Compile the ds file (*.ds, *.ds-cpp) or converted C++ file to the exectuable.
 */
class DS_Compile {
public:
    DS_Compile(CompileType type, QString dsFile, QString cppFile, QString outFile);

    CompileType compileType_ = CompileType::DS;

private:
    QString dsFile_;

    QString cppFile_;

    QString outFile_;
};

#endif // DS_COMPILE_H
