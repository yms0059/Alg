#include<stdio.h>

int fibonacci(int n);

int main()
{
	int number;
	int i;
	printf("숫자를 입력하세요 : ");
	scanf("%d", &number);
	for (i = 0; i < number; i++) {
		printf("%d ", fibonacci(i));
	}
	printf("\n\n");
	return 0;

}

// fibonacci
int fibonacci(int n)
{
	if (n < 2)return n;
	else {
		return fibonacci(n - 1) + fibonacci(n - 2);
	}
}