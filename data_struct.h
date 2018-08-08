// data_struct.h - (c) Tyler Burdsall 2018
// 
// Contains the struct definitions for a point and node as well
// as the function declarations for operations on a point.
#ifndef DATA_STRUCT
#define DATA_STRUCT
#include <stdlib.h>

typedef struct point
{
    double x; 
    double y;
} point;

typedef struct node
{
    point* data;
    struct node* next;
} node;

point  p0; // Global variable that will be used for the compare function
void   swap(point*, point*);
double distance (const point*, const point*);
int    orientation(const point*, const point*, const point*);
int    compare(const void*, const void*);
#endif
