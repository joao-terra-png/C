#include <stdio.h>
#include <stdlib.h>

//linked list
struct st_node{
    int value;
    struct st_node *next;
};

typedef struct st_node node;

int empty(node *ll){
    if(ll->next == NULL){
        return 1;
    }else{
        return 0;
    }
} 

void start(node *ll){
    ll->next = NULL;
}

void release(node *ll){
    if(!empty(ll)){
        node *nextNode, *current;
        current = ll->next;
        while(current != NULL){
            nextNode = current->next;
            free(current);
            current = nextNode;
        }
    }
}

void print(node *ll){
    if(empty(ll)){
        printf("List is empty.\n\n");
        return;
    }
    node *tmp;
    tmp = ll->next;

    while(tmp != NULL){
        printf("%d ", tmp->value);
        tmp = tmp->next;
    }
    printf("\n\n");
}

void insertBeginning(node *ll){
    node *new = (node*)malloc(sizeof(node));
    if(!new){
        printf("No memory available.\n");
        exit(1);
    }
    printf("Enter value: ");
    scanf("%d", &new->value);

    node *oldHead = ll->next;

    ll->next = new;
    new->next = oldHead;
}

void insertEnding(node *ll){
    node *new = (node*)malloc(sizeof(node));
    if(!new){
        printf("No memory available.\n");
        exit(1);
    }
    printf("Enter value: ");
    scanf("%d", &new->value);
    new->next = NULL;

    if(empty(ll)){
        ll->next = new;
    }else{
        node *tmp = ll->next;

        while(tmp->next != NULL){
            tmp = tmp->next;
        }
        tmp->next = new;
    }
}


void option(node *ll, int op){
    switch(op){
        case 0:
            release(ll);
            break;
        case 1:
            print(ll);
            break;
        case 2:
            insertBeginning(ll);
        case 3:
            insertEnding(ll);
            break;
        case 4:
            start(ll);
            break;
        default:
            printf("Invalid command.\n\n");
    }
}

int menu(){
    int opt;

    printf("Select option: \n");    
    printf("[0] - Exit: \n");    
    printf("[1] - Print: \n");    
    printf("[2] - Insert node in the beginning: \n");    
    printf("[3] - Insert node in the ending: \n");    
    printf("[4] - Clear list: \n");    
    printf("Option: ");
    scanf("%d", &opt);

    return opt;
}

int main(){
    node *ll = (node*)malloc(sizeof(node));

    if(!ll){
        printf("No memory available.");
        exit(1);
    }
    start(ll);
    int opt;

    do{
        opt = menu();
        option(ll, opt);
    }while(opt);
    free(ll);

    return 0;
}