#include <stdio.h>
#include "testlib.h"

int main()
{
	int num1, num2;

	printf("첫 번째 수: ");
	scanf("%d", &num1);
	printf("두 번째 수: ");
	scanf("%d", &num2);

	printf("%d + %d = %d\n", num1, num2, add(num1, num2));
	printf("%d - %d = %d\n", num1, num2, subtract(num1, num2));
	printf("%d * %d = %d\n", num1, num2, multiply(num1, num2));
	printf("%d / %d = %d\n", num1, num2, divide(num1, num2));

	return 0;
}
