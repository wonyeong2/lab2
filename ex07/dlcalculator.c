#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dlfcn.h>
#include "math.h"

int main() {
	
	void *handle;
	int (*add)(int, int), (*subtract)(int, int), (*multiply)(int, int), (*divide)(int, int);
	int num1, num2;
	char *error;

	handle = dlopen("./lib/libshare.so", RTLD_LAZY);
	if(!handle) {
		fputs (dlerror(), stderr);
		exit(1);
	}
	
	add = dlsym(handle, "add");
	if ((error = dlerror()) != NULL) {
		fprintf(stderr, "%s", error);
		exit(1);
	}
	subtract = dlsym(handle, "subtract");
	if ((error = dlerror()) != NULL) {
		fprintf(stderr, "%s", error);
		exit(1);
	}
	multiply = dlsym(handle, "multiply");
	if ((error = dlerror()) != NULL) {
		fprintf(stderr, "%s", error);
		exit(1);
	}
	divide = dlsym(handle, "divide");
	if ((error = dlerror()) != NULL) {
		fprintf(stderr, "%s", error);
		exit(1);
	}

	printf("첫 번째 수 : ");
	scanf("%d", &num1);
	printf("두 번째 수 : ");
	scanf("%d", &num2);

	printf("%d + %d = %d\n", num1, num2, (*add)(num1, num2));
	printf("%d - %d = %d\n", num1, num2, (*subtract)(num1, num2));
	printf("%d * %d = %d\n", num1, num2, (*multiply)(num1, num2));
	printf("%d / %d = %d\n", num1, num2, (*divide)(num1, num2));

	dlclose(handle);

	return 0;
}
