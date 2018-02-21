#include<stdio.h>
#include<stdlib.h>
#include<time.h>		

/*
  ������ -> ���ڸ����� 
*/

int H[100];
int n, k, i, e;

void inPlaceHeapsort(int A[], int n);
void buildHeap(int A[], int n);
void insertItem(int A[], int i);
void downHeap(int A[], int i, int last);
void printHeap();
void swap(int *a, int *b);

void main() {

	while (1)
	{
		scanf("%d", &n);
		for (i = 1; i <= n; i++)
		{
			scanf("%d", &H[i]);
		}
		inPlaceHeapsort(H, n);
		printf("\n");
		printHeap();
		break;
	}
}

void inPlaceHeapsort(int A[], int n) {
	int i;

	buildHeap(A, n);  //�Ϸ¹��� key���� �������Ѵ� ->buildHeap���� Go

	for (i = n; i >= 2; i--) {
		swap(&A[i], &A[1]);  //���� ù��° �ε������ִ� Key���� ���� ũ�⶧���� ���� �ڷ� �ű��.
		downHeap(A, 1, i - 1); //����ū Key���� �ڿ� ��ġ�ϱ⶧���� Last���� i-1�� �Ѵ�.
	}
}

void buildHeap(int A[], int n) {
	int i;
	for (i = 2; i <= n; i++) { 
		insertItem(A, i);  //key���� ���Ͽ� �����Ѵ�
	}
}

void insertItem(int A[], int i) {  //�������ϴ� ���� �θ�� �ڽ���Key������ ũ��

	if (i == 1)  
		return;

	if (A[i] <= A[i / 2])  
		return;

	swap(&A[i], &A[i / 2]);

	i /= 2;

	insertItem(A, i);
}

void downHeap(int A[], int i, int last) {// �����ĵȰ��� ���ڸ����� �񱳸� ���� ������������ ���� �����Ѵ�.

	int left, right, greater; //

	left = i * 2;  //���� �ڽ�
	right = i * 2 + 1;//������ �ڽ�

	if (left > last)
		return;

	greater = left; 

	if (right <= last) {
		if (A[right] > A[greater])
			greater = right;
	}

	if (A[i] >= A[greater])
		return;

	swap(&A[i], &A[greater]);

	downHeap(A, greater, last);
}

void printHeap() {
	int i;
	if (n == 0) {
		printf("���� ����");
		return;
	}
	for (i = 1; i < n + 1; i++) {
		printf("%d", H[i]);
		printf("\n");
	}
}


void swap(int *a, int *b) {
	int tmp;
	tmp = *a;
	*a = *b;
	*b = tmp;

}