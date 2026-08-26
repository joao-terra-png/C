#ifndef STACK_H
#define STACK_H

#define STACKSIZE 10

typedef struct {
    int vector[STACKSIZE];
    int top;
} Stack;

void create(Stack*);
void push(Stack*, int, int*);
void pop(Stack*, int*, int*);
int is_empty(Stack*);
int is_full(Stack*);

#endif