#include <stdio.h>

int main(){
	/*  0   1    2    3   4
	 *----------------------
	 *|   |    |    |   |  |
	 *----------------------
	 *
	*/
	int values[5];

	for(int i = 0; i < 5; i++){
		printf("Enter value %d/5: ", (i+1));
		scanf("%d", &values[i]);
	}

	printf("Entered values: \n");
	for(int i = 0; i < 5; i++){
		printf("%d\n", values[i]);
	}

	printf("%p %d\n", &values[0], values[0]);
	printf("%p %d\n", values, values[0]);

	return 0;
}