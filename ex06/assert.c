#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

void my_assert(int num){
	assert(((num >= 0) && (num <= 100)));
	printf("var : num = %d \n", num);
}

int main(int argc, char *argv[]){

	int num;

	if (argc < 2){
		fprintf(stderr, "Usage : assert_test aNumber\n (0 <= aNumber <= \n");
		exit(1);
	}

	num = atoi(argv[1]);
	my_assert(num);
}
