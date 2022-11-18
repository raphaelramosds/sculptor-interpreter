#ifndef PUTSPHERE_H 
#define PUTSPHERE_H 

#include "figurageometrica.h"
#include "sculptor.h"

/**
 * @brief PutSphere add a 3D sphere
 * @details This concrete class is used to add a sphere on an especific index
 * */

class PutSphere : public FiguraGeometrica {

    int xcenter, ycenter, zcenter, radius;
    float r, g, b, a;

    public:
        PutSphere(int _xcenter, int _ycenter, int _zcenter, int _radius, float _r, float _g, float _b, float _a);    
        void draw(Sculptor &t);
};

#endif