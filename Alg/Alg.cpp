#include<stdio.h>

int gcd(int m,int n);

int main()
{
	int m, n;//�μ� �Է�
	int i;
	printf("���ڸ� �Է��ϼ��� : ");
	scanf("%d", &m);
	scanf("%d", &n);
	

	return 0;

}

// �ִ� �����
int gcd(int m,int n)
{
	if (m < n) {
		int tmp = m;
		m = n;
		n = tmp;
	}
	if (m%n == 0) {
		return n;
	}
	else {
		return gcd(n, m%n);
	}
}

int gcds(int m, int n)
{
	if (m == 0) {
		return n;
	}
	else {
		return gcd(n, m%n);
	}
}