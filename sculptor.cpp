#include <iostream>
#include <fstream>
#include <cmath>

#include "headers/sculptor.h"
#include "headers/voxel.h"

// @constructor Sculptor: allocate a 3D matrix

Sculptor::Sculptor(int _nx, int _ny, int _nz) {

    nx = _nx; ny = _ny; nz = _nz;

    std::cout << "log: allocating matrix" << std::endl;

    v = new Voxel**[_nz];

    v[0] = new Voxel*[_nx * _nz];

    for (int p = 1; p < nz; p++)
        v[p] = v[p - 1] + _nx;

    v[0][0] = new Voxel[_nx * _ny * _nz];

    for (int l = 1; l < _nx * _nz; l++ )
        v[0][l] = v[0][l - 1] + _ny;
	
	// Set initial value of all elements to isOn = false
	// one need to do that because you aren't sure if the initial
	// value is true (it can be anything)
	
	for (int l = 1; l < _nx * _nz * _ny; l++ )
        v[0][0][l].isOn = false;
}

// @destructor ~Sculptor: deallocate a 3D matrix

Sculptor::~Sculptor() {
    std::cout << "log: deallocating matrix" << std::endl;
    delete v[0][0];
    delete v[0];
    delete v;
}

// setColor: set current color

void Sculptor::setColor(float r, float g, float b, float a) {
    this->r = r; this->g = g; this->b = b; this->a = a;
}

// putVoxel: put a voxel on a specific index [x][y][z]

void Sculptor::putVoxel(int x, int y, int z) {
    if ((x < nx && x >= 0) && (y < ny && y >= 0) && (z < nz && z >= 0)) {
        v[x][y][z].isOn = true;
        v[x][y][z].r = r; v[x][y][z].g = g; v[x][y][z].b = b;
        v[x][y][z].a = a;
    } else {
        std::cout << "error: incorrect index";
    }
}

// cutVoxel: remove a voxel of a specific index [x][y][z]

void Sculptor::cutVoxel(int x, int y, int z) {
    if ((x < nx && x >= 0) && (y < ny && y >= 0) && (z < nz && z >= 0)) {
        v[x][y][z].isOn = false;
    } else {
        std::cout << "error: incorrect index";
    }
}

// writeOFF: exports a OFF file according with the given drawing instructions

void Sculptor::writeOFF(const char* filename) {

    unsigned int voxels = 0;
    unsigned int currface = 0;

    // Calculate amount of voxels with property isOn = true

    for (int p = 0; p < nz; p++) {
        for (int l = 0; l < nx; l++) {
            for (int c = 0; c < ny; c++) {
                if (v[p][l][c].isOn == true)
                    voxels += 1;
            }
        }
    }

    std::cout << "log: preparing " << voxels << " voxels" << std::endl;

    // There will be (voxels * 8) vertexes and (voxels * 6) faces!

    std::ofstream fout;

    std::cout << "log: creating " << filename << std::endl;
    fout.open(filename, std::ios::out);

    if (fout.is_open()) {

        // Header

        std::cout << "log: building header" << std::endl;

        fout << "OFF" << std::endl;
        fout << voxels * 8 << " " << voxels * 6 << " " << 0 << std::endl;

        // Vertexes coordinates based on [x y z]

        std::cout << "log: building vertexes coordinates" << std::endl;

		fout << std::fixed; // @enumerate fixed: força a saida como nomenclatura de ponto fixo. Ex: 3.59 -> 3.590000
		
        for (int p = 0; p < nz; p++) {
            for (int l = 0; l < nx; l++) {
                for (int c = 0; c < ny; c++) {
                    if (v[p][l][c].isOn == true) {
                        fout << -0.5 + l << " " <<  0.5 + c << " " << -0.5 + p << std::endl;
                        fout << -0.5 + l << " " << -0.5 + c << " " << -0.5 + p << std::endl;
                        fout <<  0.5 + l << " " << -0.5 + c << " " << -0.5 + p << std::endl;
                        fout <<  0.5 + l << " " <<  0.5 + c << " " << -0.5 + p << std::endl;
                        fout << -0.5 + l << " " <<  0.5 + c << " " <<  0.5 + p << std::endl;
                        fout << -0.5 + l << " " << -0.5 + c << " " <<  0.5 + p << std::endl;
                        fout <<  0.5 + l << " " << -0.5 + c << " " <<  0.5 + p << std::endl;
                        fout <<  0.5 + l << " " <<  0.5 + c << " " <<  0.5 + p << std::endl;
                    }
                }
            }
        }

        // Faces specifications

        std::cout << "log: building faces specifications" << std::endl;

        for (int p = 0; p < nz; p++) {
            for (int l = 0; l < nx; l++) {
                for (int c = 0; c < ny; c++) {

                    if (v[p][l][c].isOn == true) {
                        // specicifies face whose vertexes have indexes [ a b c d ]

                        fout << 4 << " " << 0 + currface << " " << 3 + currface << " " << 2 + currface << " " << 1 + currface << " " << v[p][l][c].r << " " << v[p][l][c].g << " " << v[p][l][c].b << " " << v[p][l][c].a << std::endl;
                        fout << 4 << " " << 4 + currface << " " << 5 + currface << " " << 6 + currface << " " << 7 + currface << " " << v[p][l][c].r << " " << v[p][l][c].g << " " << v[p][l][c].b << " " << v[p][l][c].a << std::endl;
                        fout << 4 << " " << 0 + currface << " " << 1 + currface << " " << 5 + currface << " " << 4 + currface << " " << v[p][l][c].r << " " << v[p][l][c].g << " " << v[p][l][c].b << " " << v[p][l][c].a << std::endl;
                        fout << 4 << " " << 0 + currface << " " << 4 + currface << " " << 7 + currface << " " << 3 + currface << " " << v[p][l][c].r << " " << v[p][l][c].g << " " << v[p][l][c].b << " " << v[p][l][c].a << std::endl;
                        fout << 4 << " " << 3 + currface << " " << 7 + currface << " " << 6 + currface << " " << 2 + currface << " " << v[p][l][c].r << " " << v[p][l][c].g << " " << v[p][l][c].b << " " << v[p][l][c].a << std::endl;
                        fout << 4 << " " << 1 + currface << " " << 2 + currface << " " << 6 + currface << " " << 5 + currface << " " << v[p][l][c].r << " " << v[p][l][c].g << " " << v[p][l][c].b << " " << v[p][l][c].a << std::endl;

                        // and increment another indexes by 8, i.e, [ a + 8k b + 8k c + 8k d + 8k ]

                        currface += 8;
                    }
                }
            }
        }

        std::cout << "success: file " << filename << " exported" << std::endl;

        fout.close();
    }
}