#include "headers/sculptor.h"
#include "headers/cutsphere.h"

CutSphere::CutSphere(int _xcenter, int _ycenter, int _zcenter, int _radius)
{
    xcenter = _xcenter; 
    ycenter = _ycenter;
    zcenter = _zcenter;
    radius = _radius;
}

void CutSphere::draw(Sculptor &t)
{
    for (int p = zcenter - radius; p < zcenter + radius; p++)
    {
        for (int l = xcenter - radius; l < xcenter + radius; l++)
        {
            for (int c = ycenter - radius; c < ycenter + radius; c++)
            {
                float x = l - xcenter;
                float y = c - ycenter;
                float z = p - zcenter;

                if (x * x + y * y + z * z < radius * radius)
                    t.cutVoxel(l, c, p);
            }
        }
    }
}