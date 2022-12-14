#ifndef CUTELLIPSOID_H 
#define CUTELLIPSOID_H 

#include "figurageometrica.h"
#include "sculptor.h"

/**
 * @brief CutEllipsoid removes a 3D ellipsoid
 * @details This concrete class is used to cut an ellipsoid of a specific position
 * */

class CutEllipsoid : public FiguraGeometrica {

    int xcenter, ycenter, zcenter, rx, ry, rz;

    public:
        CutEllipsoid(int _xcenter, int _ycenter, int _zcenter, int _rx, int _ry, int _rz);    
        void draw(Sculptor &t);
};

#endif