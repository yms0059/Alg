#include<stdio.h>
#include<stdlib.h>
#include<time.h>		

/*
  힙정렬 -> 제자리정렬 
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

	buildHeap(A, n);  //일력받은 key값을 힙정렬한다 ->buildHeap으로 Go

	for (i = n; i >= 2; i--) {
		swap(&A[i], &A[1]);  //가장 첫번째 인덱스에있는 Key값이 가장 크기때문에 가장 뒤로 옮긴다.
		downHeap(A, 1, i - 1); //가장큰 Key값이 뒤에 위치하기때문에 Last값을 i-1로 한다.
	}
}

void buildHeap(int A[], int n) {
	int i;
	for (i = 2; i <= n; i++) { 
		insertItem(A, i);  //key값을 비교하여 정렬한다
	}
}

void insertItem(int A[], int i) {  //힙정렬하는 로직 부모는 자식의Key값보다 크다

	if (i == 1)  
		return;

	if (A[i] <= A[i / 2])  
		return;

	swap(&A[i], &A[i / 2]);

	i /= 2;

	insertItem(A, i);
}

void downHeap(int A[], int i, int last) {// 힙정렬된것을 제자리정렬 비교를 통해 오름차순으로 수를 정렬한다.

	int left, right, greater; //

	left = i * 2;  //왼쪽 자식
	right = i * 2 + 1;//오른쪽 자식

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
		printf("힙이 없어");
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