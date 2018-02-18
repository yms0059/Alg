#include<stdio.h>

int gcd(int m,int n);

int main()
{
	int m, n;//두수 입력
	int i;
	printf("숫자를 입력하세요 : ");
	scanf("%d", &m);
	scanf("%d", &n);
	

	return 0;

}

// 최대 공약수
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