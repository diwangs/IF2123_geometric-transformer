# Geometric Transformer for IF2123
A program to simulate a geometric transformation in a vector space. Written in C++ using OpenGL library. 
Made to fulfill an assignment for Geometric Algebra course at Institut Teknologi Bandung.

## Installation

1. Download [freeglut 3.0.0 for MinGW](http://files.transmissionzero.co.uk/software/development/GLUT/freeglut-MinGW.zip).
2. Extract to your MinGW folder.

## Compile and Build

Main Program:
```
g++ src/main.cpp inc/titik.cpp inc/matriks.cpp -lfreeglut -lopengl32 -lglu32 -o bin/algeo
```

Driver File:
```
g++ test/titik.cpp inc/titik.cpp inc/matriks.cpp -lfreeglut -lopengl32 -lglu32 -o bin/titik
g++ test/matriks.cpp inc/titik.cpp inc/matriks.cpp -lfreeglut -lopengl32 -lglu32 -o bin/matriks
```
