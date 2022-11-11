#ifndef PUTVOXEL_H 
#define PUTVOXEL_H 

#include "figurageometrica.h"
#include "sculptor.h"

class PutVoxel : public FiguraGeometrica {
    int l, c, p;
    float r,g,b,a;

    public:
        PutVoxel(int _l, int _c, int _p, float _r, float _g, float _b, float _a);    
        void draw(Sculptor &t);
};

#endif