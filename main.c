// main.c - (c) Tyler Burdsall 2018
//
// Entry point for the convex hull program. Given an input from
// stdin containing point data, this program will generate the
// list of points that form the smallest convex hull using
// the Graham Scan algorithm. This code is inspired from the algorithm
// available on Wikipedia as well as the C++ implementation by Manish Bhojasia
// and can be found here: 
//
// https://www.sanfoundry.com/cpp-program-implement-graham-scan-algorithm-find-convex-hull/
//
// This algorithm allows for the convex hull to be found in O(n log n) time. 
#include "stack.h"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

// Returns a node pointer to the first node in a stack containing
// the list of points in the convex hull
node*
convex_hull(point* points, int n)
{
    // Initiate global point's x and y values,
    // initiate hull pointer
    p0.x = 0;
    p0.y = 0;
    node* hull = NULL;

    // If the given amount of points is less than 3,
    // generating a convex hull is impossible
    if (n < 3)
    {
        return hull;
    }

    // Find the coordinate with the smallest y-value. Ties are broken
    // by comparing the x-value.
    int ymin, min;
    ymin = points[0].y;
    min = 0;
    for(int i = 1; i < n; ++i)
    {
        int y = points[i].y;
        if ((y < ymin) || (ymin == y && points[i].x < points[min].x))
        {
            ymin = points[i].y;
            min = i;
        }
    }
    
    // Place the point with the smallest y-value in the beginning.
    // This will be used to compare against the other points and sort
    // by polar angle.
    swap(&points[0], &points[min]);
    p0 = points[0];

    // Use the built-in quicksort function beginning with the 2nd element.
    // The compare function can be found in data_struct.c 
    qsort(&points[1], n-1, sizeof(point), compare);

    // Push the first three points into the output stack to compare 
    // orientation.
    stack_push(&hull, &points[0]);
    stack_push(&hull, &points[1]);
    stack_push(&hull, &points[2]);
    for(int i = 3; i < n; ++i)
    {
        // While the orientation isn't valid, pop points from the stack 
        while(orientation(stack_next_to_top(hull), stack_peek(hull), &points[i]) != 2)
        {
            stack_pop(&hull);
        }
        // Push the current point onto the stack
        stack_push(&hull, &points[i]);
    }

    // Return the convex hull
    return hull;
}

int
main(int argc, char* argv[])
{
    // The program takes input from stdin in this form:
    // 
    // N
    // x_0 y_0
    // x_1 y_1
    // ... ...
    //
    // where N is the number of points and each x- and y-value
    // is a double corresponding to the location on a cartesian plane.
    int n;
    int rc = scanf("%d", &n);
    if (!rc)
    {
        fprintf(stderr, "Unable to read in the first value from the file\n"); 
        return -1;
    }

    // Dynamically generate an array of points on the heap to handle
    // large sets of data, then read in the points into each respective
    // index.
    point* points = malloc(n * sizeof(point));
    for(int i = 0; i < n; ++i)
    {
        rc = scanf("%lf %lf", &points[i].x, &points[i].y);
        if(!rc)
        {
            fprintf(stderr, "Error: garbage data in text file!\n"); 
            return -1;
        }
    }

    // Used to measure how long it takes to generate the convex hull itself
    clock_t t;
    t = clock();
    node* hull = convex_hull(points, n);
    t = clock() - t;
    double elapsed = ((double)t)/CLOCKS_PER_SEC;
    printf("Found convex hull in %0.8f seconds:\n", elapsed);

    // Prints the stack in reverse order such that the first item pushed in the stack
    // is the first to be displayed.
    stack_print(hull);
    printf("\n");

    // Free memory to avoid memory leaks
    free(points);
    points = NULL;
    stack_free(&hull);
    hull = NULL;
    return 0;
}
