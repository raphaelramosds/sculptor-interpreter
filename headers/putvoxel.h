#ifndef PUTVOXEL_H 
#define PUTVOXEL_H 

#include "figurageometrica.h"
#include "sculptor.h"

/**
 * @brief PutVoxel addes a voxel on a 3D matrix
 * @details This concrete class is used to add a volume element on a specific index
 * */


class PutVoxel : public FiguraGeometrica {
    int l, c, p;
    float r,g,b,a;

    public:
        PutVoxel(int _l, int _c, int _p, float _r, float _g, float _b, float _a);    
        void draw(Sculptor &t);
};

#endif