#include "headers/sculptor.h"
#include "headers/putellipsoid.h"

PutEllipsoid::PutEllipsoid(int _xcenter, int _ycenter, int _zcenter, int _rx, int _ry, int _rz, float _r, float _g, float _b, float _a)
{
    xcenter = _xcenter;
    ycenter = _ycenter;
    zcenter = _zcenter;
    rx = _rx;
    ry = _ry;
    rz = _rz;
    r = _r;
    g = _g;
    b = _b;
    a = _a;
}

void PutEllipsoid::draw(Sculptor &t)
{
    float s = xcenter, u = ycenter;

    for (int p = zcenter - rz; p < zcenter + rz; p++)
    {
        for (int l = s - rx; l < s + rx; l++)
        {
            for (int c = u - ry; c < u + ry; c++)
            {

                float x = (float)(l - s) / rx;
                float y = (float)(c - u) / ry;
                float z = (float)(p - zcenter) / rz;

                if (x * x + y * y + z * z <= 1)
                    t.putVoxel(l, c, p);
            }
        }
    }
}