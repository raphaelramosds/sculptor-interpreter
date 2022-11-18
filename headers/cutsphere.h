#ifndef CUTSPHERE_H 
#define CUTSPHERE_H 

#include "figurageometrica.h"
#include "sculptor.h"

/**
 * @brief CutSphere removes a 3D sphere
 * @details This concrete class is used to cut a sphere of a specific position
 * */

class CutSphere : public FiguraGeometrica {

    int xcenter, ycenter, zcenter, radius;

    public:
        CutSphere(int _xcenter, int _ycenter, int _zcenter, int _radius);    
        void draw(Sculptor &t);
};

#endif