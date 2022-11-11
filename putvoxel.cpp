#include <iostream>

#include "headers/sculptor.h"
#include "headers/putvoxel.h"

PutVoxel::PutVoxel(int _l, int _c, int _p, float _r, float _g, float _b, float _a)
{
    l = _l; c = _c; p = _p;
    r = _r; g = _g; b = _b;
    a = _a;
}

void PutVoxel::draw(Sculptor &t)
{
    t.setColor(r, g, b, a);
    t.putVoxel(l, c, p);
}