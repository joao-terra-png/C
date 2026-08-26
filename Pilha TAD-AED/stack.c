#include "stack.h"

void create(Stack *s){
    for(int i = 0; i < STACKSIZE; i++){
        s->vector[i] = 0;
    }
    s->top = 0;
}

void push(Stack *s, int val, int *ok){
    if(is_full(s)){
        *ok = 0;
    }else{
        s->vector[s->top] = val;
        s->top = s->top + 1;
        *ok = 1;
    }
}

void pop(Stack *s, int *val, int *ok){
    if(is_empty(s)){
        *ok = 0;
    }else{
        s->top = s->top - 1;
        *val = s->vector[s->top];
        s->vector[s->top] = 0;
        *ok = 1;
    }
}

int is_empty(Stack *s){
    return s->top == 0;
}

int is_full(Stack *s){
    return s->top == STACKSIZE;
}