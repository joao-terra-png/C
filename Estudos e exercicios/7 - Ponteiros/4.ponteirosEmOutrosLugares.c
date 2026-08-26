#include <stdio.h>

int main(){
	/*  0   1    2    3   4
	 *----------------------
	 *|   |    |    |   |  |
	 *----------------------
	 *
	 * int = 4 bytes
	 * bit 0 / 1
	 * byte 0000 0001
	 * 0000 0000 0000 0000 0000 0000 0000 0001
	 * 0000 0000 0000 0000 0000 0000 0000 0010
	*/
	int values[5] = {1, 2, 3, 4, 5};
	
	for(int i = 0; i < 5; i++){
        printf("Value %d worths %ld bytes\n", values[i], sizeof(values[i]));	    
	}
	printf("Array values worths %ld bytes\n", sizeof(values));
	
	printf("values[0] worths %d and memory adress is %p\n", values[0], values[0]);
	printf("*values worths %d and memory adress is %p\n", *values, *values);
	
	printf("*values+1 worths %d and memory adress is %p\n", *values+1, *values+1);
	printf("*values+1 worths %d and memory adress is %p\n", *values+2, *values+2);
	printf("*values+1 worths %d and memory adress is %p\n", *values+3, *values+3);
	printf("*values+1 worths %d and memory adress is %p\n", *values+4, *values+4);
	
	
	return 0;
}