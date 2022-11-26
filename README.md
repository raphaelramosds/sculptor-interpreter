# Sculptor interpreter

## What is Sculptor

Sculptor is a C++ class created from sketch that can draw 3D sculptures with volume elements (voxels).

## His interpreter

Sculptor has the power of export `.OFF` files that can be imported on 3D softwares as [Meshlab](https://www.meshlab.net/) and [Geomview](http://www.geomview.org/) in order to draw the sculpture whose instructions are compiled on this sort of file.

But, before it exports that `OFF`, one must give Sculptor instructions such as cut/put an ellipsoid, a sphere, a voxel and a box. So, this repo hosts an inplementation of an interpreter that can read any text file - with valid instructions - and generate a `OFF` file related to it.

## Documentation

One can see the documentation of this interpreter[right here](https://raphaelramosds.github.io/sculptor/index.html).