#include<stdio.h>

int sum(int n);

int main()
{
	int number;
	printf("���ڸ� �Է��ϼ��� : ");
	scanf("%d", &number);
	printf("1���� %d������ �� : %d\n", number, sum(number));

	return 0;
}

// ���� ���ϴ� ����Լ�
int sum(int n)
{
	if (n <= 0)
		return 0;
	return n + sum(n - 1);
}