#include<stdio.h>

int sum(int n);

int main()
{
	int number;
	printf("숫자를 입력하세요 : ");
	scanf("%d", &number);
	printf("1부터 %d까지의 합 : %d\n", number, sum(number));

	return 0;
}

// 합을 구하는 재귀함수
int sum(int n)
{
	if (n <= 0)
		return 0;
	return n + sum(n - 1);
}