#include <iostream>

#include "headers/sculptor.h"
#include "headers/cutvoxel.h"

CutVoxel::CutVoxel(int _l, int _c, int _p)
{
    l = _l;
    c = _c;
    p = _p;
}

void CutVoxel::draw(Sculptor &t)
{
    t.cutVoxel(l,c,p);
}