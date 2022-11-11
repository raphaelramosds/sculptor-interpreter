#ifndef INTERPRETER_H
#define INTERPRETER_H

#include <fstream>

class Interpreter
{
    std::ifstream fin;

    public:
        Interpreter();
        ~Interpreter();
        void parse(char *filename, char *path);
};

#endif