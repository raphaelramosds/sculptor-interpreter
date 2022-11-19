#ifndef PUTBOX_H 
#define PUTBOX_H 

#include "figurageometrica.h"
#include "sculptor.h"

/**
 * @brief PutBox add a 3D box
 * @details This concrete class is used to add a box on an especific index
 * @param x0 start index on x
 * @param x1 end index on x
 * @param y0 start index on y
 * @param y1 end index on y
 * @param z0 start index on z
 * @param z1 end index on z
 * */

class PutBox : public FiguraGeometrica {
    int x0, x1, y0, y1, z0, z1;
    float r,g,b,a;

    public:
        PutBox(int _x0, int _x1, int _y0, int _y1, int _z0, int _z1, float _r, float _g, float _b, float _a);    
        void draw(Sculptor &t);
};

#endif