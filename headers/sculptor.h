#ifndef SCULPTOR_H
#define SCULPTOR_H

#include "voxel.h"

/**
 * @brief The Sculptor class allows you to draw any sculpture with voxel elements
 * @details This class dinamically allocate a three dimension matrix and makes it available for you to draw any sculpture with cubes whose dimensions are 1 x 1 x 1
 * */

class Sculptor
{
    private:
        Voxel ***v;       // 3D matrix
        int nx, ny, nz;   // Dimensions
        float r, g, b, a; // Current drawing color
        
    public:
        /**
        * @details Sculptor is the constructor. It allocates a 3D matrix based on the number of lines, columns and planes. You can access the element of the `x` th line, `y` th column and `z` th plane with `v[i][j][k]`
        * @param _nx lines
        * @param _ny columns
        * @param _nz planes
        * */

    Sculptor(int _nx, int _ny, int _nz);

    /**
     * @details ~Sculptor deallocate a 3D matrix. It's called everytime the `.OFF` file is exported
     * */

    ~Sculptor();

    /**
     * @details Set the drawing current color, you can set it within 0.0 to 1.0.
     * If you want to pass a specific RGB color `C`, just calculate `C/255`
     * */

    void setColor(float r, float g, float b, float a);

    /**
     * @details Put a voxel on a specific index `[x][y][z]`
     * */

    void putVoxel(int x, int y, int z);

    /**
     * @details Remove a voxel of a specific index `[x][y][z]`
     * */

    void cutVoxel(int x, int y, int z);

    /**
     * @details Exports a OFF file on the current directory, according with the given drawing instructions
     * */

    void writeOFF(const char *filename);
};

#endif