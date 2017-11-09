# Geometric Transformer for IF2123
A program to simulate a geometric transformation in a vector space. Written in C++ using OpenGL library. 
Made to fulfill an assignment for Geometric Algebra course at Institut Teknologi Bandung.

## Installation

1. Download [freeglut 3.0.0 for MinGW](http://files.transmissionzero.co.uk/software/development/GLUT/freeglut-MinGW.zip).
2. Extract to your MinGW folder.

## Compile and Build

Main Program:
```
g++ src/main.cpp src/inc/poly2.cpp src/inc/matriks2.cpp src/inc/titik2.cpp -lfreeglut -lopengl32 -lglu32 -o bin/algeo
```

Test File:
```
g++ test/matriks2.cpp src/inc/matriks2.cpp -o bin/matriks2
g++ test/titik2.cpp src/inc/titik2.cpp src/inc/matriks2.cpp -o bin/titik2
g++ test/poly2.cpp src/inc/poly2.cpp src/inc/titik2.cpp src/inc/matriks2.cpp -o bin/poly2
```
