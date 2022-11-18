#include <iostream>

#include <vector>

#include "headers/figurageometrica.h"
#include "headers/interpreter.h"

int main()
{
    Interpreter* keven;

    keven = new Interpreter((char*) "assets/keven.txt");
    keven->exportf("assets/keven.off");

}