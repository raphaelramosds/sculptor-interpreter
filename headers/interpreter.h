#ifndef INTERPRETER_H
#define INTERPRETER_H

#include <fstream>
#include <vector>

#include "figurageometrica.h"

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
        std::vector<FiguraGeometrica*> parse();
        int getDimX();
        int getDimY();
        int getDimZ();
};

#endif