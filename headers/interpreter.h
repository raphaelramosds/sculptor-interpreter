#ifndef INTERPRETER_H
#define INTERPRETER_H

#include <fstream>
#include <vector>

#include "figurageometrica.h"

/**
 * @brief Intepreter
 * @details This classe basically creates a new input stream on a `txt` file filled by instructions that can be interpreted in order to draw the wished sculpture
 * */

class Interpreter
{
    /**
     * @param fin represents the input stream created
     */
    std::ifstream fin;

    char *filename;

    int dimx;
    int dimy;
    int dimz;

    public:
        /**
         * @details Intepreter is the constructor. It receives `char* _filename` as the unique parameter. This string is the path for the `txt` file to be interptreted.
         */
        Interpreter(char *_filename);
        ~Interpreter();
        /**
         * @details read the file, extracts tokens related to the concrete classes and uses Sculptor class to draw the wished three dimension sculpture
         * @param path represents the path which you want to save your `off` file
         */
        void exportf(char *path);
};

#endif