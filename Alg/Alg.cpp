#include<stdio.h>

int factorial(int n);

int main()
{
	int number;
	printf("���ڸ� �Է��ϼ��� : ");
	scanf("%d", &number);
	printf("%d�� ���丮�� : %d\n", number, factorial(number));
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