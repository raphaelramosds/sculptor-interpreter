#include "headers/sculptor.h"
#include "headers/cutellipsoid.h"

CutEllipsoid::CutEllipsoid(int _xcenter, int _ycenter, int _zcenter, int _rx, int _ry, int _rz)
{
    xcenter = _xcenter;
    ycenter = _ycenter;
    zcenter = _zcenter;
    rx = _rx;
    ry = _ry;
    rz = _rz;
}

void CutEllipsoid::draw(Sculptor &t)
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