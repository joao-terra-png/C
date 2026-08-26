#include <stdio.h>

#define STACKSIZE 10

//stack
int stack[STACKSIZE] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
int top = 0;

void list_elements(){
    printf("\n====Current Stack====\n");
    for(int i = 0; i < STACKSIZE; i++){
        printf("-");
        printf("|%d|", stack[i]);
        printf("-");
    }

    printf("\nTop: %d", top);
    printf("\n\n");
}

void push(){
    int val;
    printf("Enter value: ");
    scanf("%d", &val);
    if(top < STACKSIZE){
        stack[top] = val;
        top = top + 1;
        list_elements();
    }else{
        printf("Stack is full...\n");
    }
}

void pop(){
    if(top > 0){
        stack[top - 1] = 0;
        top = top - 1;
        list_elements();
    }else{
        printf("Stack is empty...");
    }
}

void clear(){
    for(int i = 0; i < STACKSIZE; i++){
        stack[i] = 0;
    }
    top = 0;

    list_elements();
}

int main(){
    int option = 0;

    do{
        printf("Select option: \n\n");        
        printf("[1] - Insert (push): \n");        
        printf("[2] - Remove (pop): \n");        
        printf("[3] - List: \n");        
        printf("[4] - Clear stack: \n");        
        printf("[-1] - Exit.\n");
        printf("Opcao: ");
        scanf("%d", &option);

        switch(option){
            case 1:
                push();
                break;
            case 2:
                pop();
                break;
            case 3:
                list_elements();
                break;
            case 4:
                clear();
                break;
            case -1:
                break;
            default:
                printf("Invalid option.");
        }
    }while(option != -1);

    return 0;
}