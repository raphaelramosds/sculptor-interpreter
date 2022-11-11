#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <cstdlib>

#include "headers/figurageometrica.h"
#include "headers/sculptor.h"
#include "headers/putvoxel.h"
#include "headers/interpreter.h"

Interpreter::Interpreter()
{
    std::cout << "init: reading file" << std::endl;
}

Interpreter::~Interpreter()
{
    std::cout << "success: file interpreted" << std::endl;
}

void Interpreter::parse(char *filename)
{
    // Matriz 3D e suas propriedades

    Sculptor *object;

    std::string token;
    float r, g, b, a;

    // Vetor de estruturas

    std::vector<FiguraGeometrica *> shapes;        // vetor
    std::vector<FiguraGeometrica *>::iterator its; // iterador

    // Abrir arquivo

    fin.open(filename);

    if (!fin.is_open())
    {
        std::cout << "error: file not found \n";
        exit(EXIT_FAILURE);
    }

    // Leitura do arquivo

    while(fin.good()) {

        fin >> token;

        if (!fin.good()) break;

        if (token.compare("dim") == 0) {
            int l, c, p;
            fin >> l >> c >> p;
            object = new Sculptor(l, c, p);
        } 

        if (token.compare("putvoxel") == 0) {
            int l, c, p;
            fin >> l >> c >> p;
            fin >> r >> g >> b >> a;
            shapes.push_back(new PutVoxel(l,c,p,r,g,b,a));
        }
    }
    // Desenhar formas

    for (auto it : shapes)
        it->draw(*object); // passe o endereço da matriz e não o endereço do seu ponteiro

    // Liberar bloco de figuras

    for (its = shapes.begin(); its != shapes.end(); its++)
        delete[] * its;

    object->writeOFF("assets/shape.off");
}