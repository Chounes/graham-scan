// stack.h - (c) Tyler Burdsall 2018
//
// Contains the function declarations for the stack data structure
#ifndef STACK_H
#define STACK_H
#include <stdlib.h>
#include <stdio.h>
#include "data_struct.h"

node*       create_node(point*);
void        stack_push(node**, point*);
point*      stack_peek(node*);
point*      stack_next_to_top(node*);
point*      stack_pop(node**);
void        stack_print(node*);
void        stack_free(node**);
#endif
