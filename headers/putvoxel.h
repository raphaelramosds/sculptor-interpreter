#ifndef PUTVOXEL_H 
#define PUTVOXEL_H 

#include "figurageometrica.h"
#include "sculptor.h"

/**
 * @brief PutVoxel addes a voxel on a 3D matrix
 * @details This concrete class is used to add a volume element on a specific index colored by `[r g b]`
 * */


class PutVoxel : public FiguraGeometrica {

    /**
    * @param l indicates line (x coordinate)
    * @param c indicates column (y coordinate)
    * @param p indicates plano (z coordinate)
    */

    int l, c, p;
    float r,g,b,a;

    public:
        PutVoxel(int _l, int _c, int _p, float _r, float _g, float _b, float _a);    
        void draw(Sculptor &t);
};

#endif