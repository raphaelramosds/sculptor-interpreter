#ifndef CUTBOX_H
#define CUTBOX_H

#include "figurageometrica.h"
#include "sculptor.h"

/**
 * @brief CutBox removes a 3D box
 * @details This concrete class is used to cut a box out of 3D matrix based on intervals
 * @param x0 start index on x
 * @param x1 end index on x
 * @param y0 start index on y
 * @param y1 end index on y
 * @param z0 start index on z
 * @param z1 end index on z
 * */

class CutBox : public FiguraGeometrica
{
    int x0, x1, y0, y1, z0, z1;

public:
    CutBox(int _x0, int _x1, int _y0, int _y1, int _z0, int _z1);
    void draw(Sculptor &t);
};

#endif