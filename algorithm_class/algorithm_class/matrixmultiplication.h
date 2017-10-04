#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void print2DArr(int arr[][4], int len);
void allocateEle(int(*arr)[4], int len);
void bruteForceMultiply(int a[][4], int b[][4], int(*c)[4], int len);

void _multiply(int*** a, int*** b, int*** c, int len);
void addition(int*** a, int*** b, int*** c, int len, int flag);
void extract(int a[][4], int*** b, int len, int row, int col);
void make2DArr(int*** a, int len);
void combine(int** leftUp, int** rightUp, int** leftDown, int** rightDown, int(*e)[4], int len);
void bestMultiply(int a[][4], int b[][4], int(*c)[4], int len);