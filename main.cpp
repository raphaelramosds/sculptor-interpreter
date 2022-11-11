#include <iostream>

#include "headers/interpreter.h"

int main () {
    Interpreter *file;

    file = new Interpreter();

    file->parse((char*) "assets/instrucoes.txt", (char*) "assets/keven.off");
}