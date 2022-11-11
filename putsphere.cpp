#include "headers/sculptor.h"
#include "headers/putsphere.h"

PutSphere::PutSphere(int _xcenter, int _ycenter, int _zcenter, int _radius, float _r, float _g, float _b, float _a)
{
    xcenter = _xcenter;
    ycenter = _ycenter;
    zcenter = _zcenter;
    radius = _radius;
    r = _r;
    g = _g;
    b = _b;
    a = _a;
}

void PutSphere::draw(Sculptor &t)
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
                    t.putVoxel(l, c, p);
            }
        }
    }
}