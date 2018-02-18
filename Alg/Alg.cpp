#include<stdio.h>

int factorial(int n);

int main()
{
	int number;
	printf("숫자를 입력하세요 : ");
	scanf("%d", &number);
	printf("%d의 팩토리얼 : %d\n", number, factorial(number));
}

// factorial
int factorial(int n)
{
	if (n <= 0)return 0;
	else if (n==1){
		return 1;
	}
	else {
		return n*factorial(n - 1);
	}
}