cls

g++ -c sculptor.cpp -o sculptor.o
g++ -c putvoxel.cpp -o putvoxel.o
g++ -c main.cpp -o main.o
g++ -c interpreter.cpp -o interpreter.o

g++ -o programa sculptor.o putvoxel.o main.o interpreter.o

programa

shape.off

del *.o
del programa.exe