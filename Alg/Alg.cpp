#include <stdio.h>

/*
   힙을 배열로
   가장큰 key값을 root로 한다 자식은 부모원소보다 작은 값이 들어가며 
   힙은 이진트리를 가져야한다
   ex) 1,3,4,5,7,9 가 차례대로 입력을 받으면 
       힙 배열에는 9,7,3,4,5,1 로 재배열하게 된다.
	   9는 root(가장큰값) 그의자식 7,3
	   7의 자식은 4,5 자신의 인덱스 번호의 2i(왼쪽),2i+1(오른쪽) 이 자식 배열인덱스
	   3의 자식은 1
*/ 


#define MAX_VAL 9999 //9999보다 큰수가 입력받지 않도록 해놓는다.

int H[100]; //배열의 크기를 100으로 크게
int n = 0;  //힙에 key값이 들어가면 증가
int i, key;
char  choice;

void insertItem(int key);
int removeMax();
void upHeap(int i);
void downHeap(int i);
void printHeap();


int main()
{
	H[0] = MAX_VAL; //배열 첫번째 인덱스는 가장큰값

	while (1)
	{
		scanf("%c", &choice);
		switch (choice)
		{
		case  'i':
			scanf("%d", &key);
			insertItem(key);
			printf("0\n");
			break;
		case 'd':
			key = removeMax();
			printf("%d\n", key);
			break;
		case 'p':
			printHeap();
			printf("\n");
			break;
		case 'q':
			//exit(1);
			break;

		}
	}
	return 0;
}

void insertItem(int key)
{
	(n)++;
	H[n] = key;
	upHeap(n);

}

void upHeap(int i)
{
	int k = H[i];
	int par = i / 2; //나누기 2인이유 부모를 비교하기위해
	while (H[par] < k)
	{
		H[i] = H[par];
		i = par;
		par = i / 2;
	}
	H[i] = k;
}

int removeMax()
{
	key = H[1];//인덱스1번의 값이 가장큰값이기 때문에
	H[1] = H[n];//마지막인덱스의 key값을 root에 가져다놓고
	(n)--;     //마지막 key값이 저장된 위치를 삭제
	downHeap(1);//1번 인덱스부터 재배열 하기위해서 가즈아
	return key; //삭제된 key값을 리턴(가장큰 값을 리턴 즉 root값 리턴)
}

void downHeap(int i)
{
	int lchild = 2 * i, rchild = lchild + 1; 
	int tmp = H[i];
	
	while (rchild <= n)
	{
		if (tmp >= H[lchild] && tmp >= H[rchild])
		{
			H[i] = tmp;
			return;
		}
		else if (H[lchild] > H[rchild])
		{
			H[i] = H[lchild];
			i = lchild;
		}
		else
		{
			H[i] = H[rchild];
			i = rchild;
		}
		lchild = 2 * i;
		rchild = lchild + 1;
	}

	if (lchild == n && tmp < H[lchild])
	{
		H[i] = H[lchild];
		i = lchild;
	}
	H[i] = tmp;

}

void printHeap()
{
	int i;
	if (n == 0)
	{
		printf("\nHeap is empty\n");
		return;
	}
	for (i = 1; i <= n; i++)
	{
		printf("%d ", H[i]);
	}
}