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
    for (int p = zcenter - rz; p < zcenter + rz; p++)
    {
        for (int l = xcenter - rx; l < xcenter + rx; l++)
        {
            for (int c = ycenter - ry; c < ycenter + ry; c++)
            {

                float x = (float)(l - xcenter) / rx;
                float y = (float)(c - ycenter) / ry;
                float z = (float)(p - zcenter) / rz;

                if (x * x + y * y + z * z < 1)
                    t.cutVoxel(l, c, p);
            }
        }
    }
}