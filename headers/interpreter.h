#ifndef INTERPRETER_H
#define INTERPRETER_H

#include <fstream>
#include <vector>

#include "figurageometrica.h"

/**
 * @brief Intepreter
 * @details 
 * */

class Interpreter
{
    std::ifstream fin;
    char *filename;

    int dimx;
    int dimy;
    int dimz;

    public:
        Interpreter(char* _filename);
        ~Interpreter();
        void exportf(char* path);
};

#endif