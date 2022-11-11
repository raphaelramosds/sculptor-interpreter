#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <cstdlib>

#include "headers/figurageometrica.h"
#include "headers/sculptor.h"
#include "headers/putvoxel.h"
#include "headers/cutvoxel.h"
#include "headers/putbox.h"
#include "headers/cutbox.h"
#include "headers/putsphere.h"
#include "headers/cutsphere.h"
#include "headers/putellipsoid.h"
#include "headers/cutellipsoid.h"
#include "headers/interpreter.h"

Interpreter::Interpreter()
{
    std::cout << "init: reading file" << std::endl;
}

Interpreter::~Interpreter()
{
    std::cout << "success: file interpreted" << std::endl;
}

void Interpreter::parse(char *filename, char *path)
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

    while (fin.good())
    {

        fin >> token;

        if (!fin.good())
            break;

        if (token.compare("dim") == 0)
        {
            int l, c, p;
            fin >> l >> c >> p;
            object = new Sculptor(l, c, p);
        }

        if (token.compare("putvoxel") == 0)
        {
            int l, c, p;
            fin >> l >> c >> p;
            fin >> r >> g >> b >> a;
            shapes.push_back(new PutVoxel(l, c, p, r, g, b, a));
        }

        if (token.compare("cutvoxel") == 0)
        {
            int l, c, p;
            fin >> l >> c >> p;
            shapes.push_back(new CutVoxel(l, c, p));
        }

        if (token.compare("putbox") == 0)
        {
            int x0, x1, y0, y1, z0, z1;
            fin >> x0 >> x1 >> y0 >> y1 >> z0 >> z1;
            fin >> r >> g >> b >> a;
            shapes.push_back(new PutBox(x0, x1, y0, y1, z0, z1, r, g, b, a));
        }

        if (token.compare("cutbox") == 0)
        {
            int x0, x1, y0, y1, z0, z1;
            fin >> x0 >> x1 >> y0 >> y1 >> z0 >> z1;
            shapes.push_back(new CutBox(x0, x1, y0, y1, z0, z1));
        }

        if (token.compare("putsphere") == 0)
        {
            int x0, y0, z0, radius;
            fin >> x0 >> y0 >> z0 >> radius >> r >> g >> b >> a;
            shapes.push_back(new PutSphere(x0, y0, z0, radius, r, g, b, a));
        }

        if (token.compare("cutsphere") == 0)
        {
            int x0, y0, z0, radius;
            fin >> x0 >> y0 >> z0 >> radius;
            shapes.push_back(new CutSphere(x0, y0, z0, radius));
        }

        if (token.compare("putellipsoid") == 0)
        {
            int x0, y0, z0, rx, ry, rz;
            fin >> x0 >> y0 >> z0 >> rx >> ry >> rz >> r >> g >> b >> a;
            shapes.push_back(new PutEllipsoid(x0, y0, z0, rx, ry, rz, r, g, b, a));
        }

        if (token.compare("cutellipsoid") == 0)
        {
            int x0, y0, z0, rx, ry, rz;
            fin >> x0 >> y0 >> z0 >> rx >> ry >> rz;
            shapes.push_back(new CutEllipsoid(x0, y0, z0, rx, ry, rz));
        }
    }

    // Desenhar formas

    for (auto it : shapes)
        it->draw(*object); // passamos o endereço da matriz e não o endereço do seu ponteiro

    // Liberar bloco de figuras

    for (its = shapes.begin(); its != shapes.end(); its++)
        delete[] * its;

    // Exportar OFF

    object->writeOFF(path);
}