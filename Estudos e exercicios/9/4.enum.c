#include <stdio.h>

//Enum --> enumeracao

enum days_of_week{
    monday,
    tuesday,
    wednesday,
    thursday,
    friday,
    saturday,
    sunday
}d1, d2;

int main(){
    d1 = friday;

    d2 = 4;

    if(d1 == d2){
        printf("The days are the same...\n");
    }else{
        printf("The days are not the same...\n");
    }

    return 0;
}