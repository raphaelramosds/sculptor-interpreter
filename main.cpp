#include <iostream>

#include <vector>

#include "headers/figurageometrica.h"
#include "headers/interpreter.h"

int main()
{
    Interpreter* keven, *taca;

    keven = new Interpreter((char*) "assets/keven.txt");
    keven->exportf((char*) "assets/keven.off");

    taca = new Interpreter((char*) "assets/taca.txt");
    taca->exportf((char*) "assets/taca.off");

}