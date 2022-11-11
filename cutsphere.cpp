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
    float s = xcenter, v = ycenter;

    for (int p = zcenter - radius; p < zcenter + radius; p++)
    {
        for (int l = s - radius; l < s + radius; l++)
        {
            for (int c = v - radius; c < v + radius; c++)
            {
                float x = l - s;
                float y = c - v;
                float z = p - zcenter;

                if (x * x + y * y + z * z < radius * radius)
                    t.cutVoxel(l, c, p);
            }
        }
    }
}