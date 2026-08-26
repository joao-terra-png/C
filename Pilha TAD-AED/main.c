/*
Autor: João Gabriel Azevedo Terra
RA:858032
*/

#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

void clear_screen();
void list_elements(Stack*);
void print_top(Stack*);
int stacks_are_equal(Stack*, Stack*);
void compare_stacks(Stack*);

int main(void){
    Stack stack;
    create(&stack);

    int option = 0;
    int val, ok;

    do{
        printf("Select option: \n\n");
        printf("[1] - Insert (push): \n");
        printf("[2] - Remove (pop): \n");
        printf("[3] - List: \n");
        printf("[4] - Clear stack: \n");
        printf("[5] - Print top element:\n");
        printf("[6] - Compare stacks:\n");
        printf("[-1] - Exit.\n");
        printf("Option: ");
        scanf("%d", &option);
        clear_screen();

        switch(option){
            case 1:
                printf("Enter value: ");
                scanf("%d", &val);
                push(&stack, val, &ok);
                if(!ok){
                    printf("Stack is full...\n");
                }
                list_elements(&stack);
                break;
            case 2:
                pop(&stack, &val, &ok);
                if(!ok){
                    printf("Stack is empty...\n");
                }
                list_elements(&stack);
                break;
            case 3:
                list_elements(&stack);
                break;
            case 4:
                create(&stack);
                list_elements(&stack);
                break;
            case 5:
                print_top(&stack);
                break;
            case 6:
                compare_stacks(&stack);
                break;
            case -1:
                break;
            default:
                printf("Invalid option.\n");
        }
    }while(option != -1);

    return 0;
}

void clear_screen(){
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

void list_elements(Stack *s){
    Stack aux;
    create(&aux);
    int values[STACKSIZE];
    int count = 0;
    int val, ok;

    while(!is_empty(s)){
        pop(s, &val, &ok);
        push(&aux, val, &ok);
    }

    while(!is_empty(&aux)){
        pop(&aux, &val, &ok);
        values[count] = val;
        push(s, val, &ok);
        count++;
    }

    printf("\n====Current Stack====\n");
    for(int i = 0; i < STACKSIZE; i++){
        printf("-");
        if(i < count){
            printf("|%d|", values[i]);
        }else{
            printf("|0|");
        }
        printf("-");
    }
    printf("\nTop: %d\n\n", count);

    while(!is_empty(&aux)){
        pop(&aux, &val, &ok);
        push(s, val, &ok);
    }
}

void print_top(Stack *s){
    int val, ok;

    pop(s, &val, &ok);
    if(!ok){
        printf("Stack is empty...\n");
        return;
    }
    push(s, val, &ok);
    printf("Top value: %d\n", val);
}

int stacks_are_equal(Stack *a, Stack *b){
    Stack auxA, auxB;
    create(&auxA);
    create(&auxB);
    int valA, valB, ok;
    int equal = 1;

    while(!is_empty(a) && !is_empty(b) && equal){
        pop(a, &valA, &ok);
        pop(b, &valB, &ok);
        push(&auxA, valA, &ok);
        push(&auxB, valB, &ok);
        if(valA != valB){
            equal = 0;
        }
    }

    if(!is_empty(a) || !is_empty(b)){
        equal = 0;
    }

    while(!is_empty(a)){
        pop(a, &valA, &ok);
        push(&auxA, valA, &ok);
    }
    while(!is_empty(b)){
        pop(b, &valB, &ok);
        push(&auxB, valB, &ok);
    }


    while(!is_empty(&auxA)){
        pop(&auxA, &valA, &ok);
        push(a, valA, &ok);
    }
    while(!is_empty(&auxB)){
        pop(&auxB, &valB, &ok);
        push(b, valB, &ok);
    }

    return equal;
}

void compare_stacks(Stack *s){
    Stack other;
    create(&other);
    int input, ok;

    printf("Enter the stack you wish to compare (up to %d values, -1 to stop):\n", STACKSIZE);
    for(int i = 0; i < STACKSIZE; i++){
        printf("Value %d of %d (-1 to stop): ", i + 1, STACKSIZE);
        scanf("%d", &input);
        if(input == -1){
            break;
        }
        push(&other, input, &ok);
    }

    if(stacks_are_equal(s, &other)){
        printf("The stacks are equal.\n");
    }else{
        printf("The stacks are different.\n");
    }
}