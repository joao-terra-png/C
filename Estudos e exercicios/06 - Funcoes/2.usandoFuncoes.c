#include <stdio.h>

//Usando funções 

void message(){ 
    printf("Welcome\n");
}

int sum(int num1, int num2){
    int res = num1 + num2;
    return res;
}

// 'a'
// '97'
void next_char(char character){
    printf("%c", character+1);
}

int main(){ 
    printf("hello...\n"); 
    
    message();
    
    //int returno = sum(4, 6);
    //printf("Returno = %d", returno);
    
    printf("Returno = %d\n", sum(4, 6));
    
    char chara = 'a';
    next_char(chara);
    return 0; 
}