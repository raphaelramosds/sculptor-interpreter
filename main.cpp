#include <iostream>

#include <vector>

#include "headers/figurageometrica.h"
#include "headers/interpreter.h"

void exportFig(char *filename, char *path)
{
    Sculptor *t;
    Interpreter* file;
    std::vector<FiguraGeometrica *> shapes;   // vetor
    std::vector<FiguraGeometrica *>::iterator its; // iterador

    // Interpretar o arquivo

    file = new Interpreter(filename);
    shapes = file->parse();

    // Desenhar formas

    t = new Sculptor(file->getDimX(), file->getDimY(), file->getDimZ());

    for (auto it : shapes)
        it->draw(*t); // passamos o endereço da matriz e não o endereço do seu ponteiro!

    // Liberar bloco de figuras

    for (its = shapes.begin(); its != shapes.end(); its++)
        delete[] * its;

    // Exportar OFF

    t->writeOFF(path);
}

int main()
{
    exportFig((char*) "assets/keven.txt", (char*)"assets/keven.off");
    exportFig((char*) "assets/taca.txt", (char*)"assets/taca.off");
}