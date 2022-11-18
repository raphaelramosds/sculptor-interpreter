#ifndef FIGURAGEOMETRICA_H 
#define FIGURAGEOMETRICA_H 

#include "sculptor.h"

/**
 * @brief FiguraGeometrica is the abstract class
 * @details The main idea is to understand this class as an artist who can draw any 3D shapes. Classes as PutVoxel, CutVoxel, PutBox, etc. inheritance this `draw` method
 * */

class FiguraGeometrica
{
    public:
        virtual void draw(Sculptor &t) = 0; // não preciso implementar ela na super classe
};

#endif