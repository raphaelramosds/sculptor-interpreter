#ifndef CUTVOXEL_H
#define CUTVOXEL_H

#include "figurageometrica.h"
#include "sculptor.h"

class CutVoxel : public FiguraGeometrica {
    int l, c, p;

    public:
        CutVoxel(int _l, int _c, int _p);
        void draw(Sculptor &t);
};

#endif