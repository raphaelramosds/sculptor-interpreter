#ifndef PUTELLIPSOID_H 
#define PUTELLIPSOID_H 

#include "figurageometrica.h"
#include "sculptor.h"

/**
 * @brief PutEllipsoid add a 3D ellipsoid
 * @details This concrete class is used to add an ellipsoid on an especific index
 * */

class PutEllipsoid : public FiguraGeometrica {

    int xcenter, ycenter, zcenter, rx, ry, rz;
    float r, g, b, a;

    public:
        PutEllipsoid(int _xcenter, int _ycenter, int _zcenter, int _rx, int _ry, int _rz, float _r, float _g, float _b, float _a);    
        void draw(Sculptor &t);
};

#endif