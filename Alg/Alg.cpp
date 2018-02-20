#include <stdio.h>

/*
   ���� �迭��
   ����ū key���� root�� �Ѵ� �ڽ��� �θ���Һ��� ���� ���� ���� 
   ���� ����Ʈ���� �������Ѵ�
   ex) 1,3,4,5,7,9 �� ���ʴ�� �Է��� ������ 
       �� �迭���� 9,7,3,4,5,1 �� ��迭�ϰ� �ȴ�.
	   9�� root(����ū��) �����ڽ� 7,3
	   7�� �ڽ��� 4,5 �ڽ��� �ε��� ��ȣ�� 2i(����),2i+1(������) �� �ڽ� �迭�ε���
	   3�� �ڽ��� 1
*/ 


#define MAX_VAL 9999 //9999���� ū���� �Է¹��� �ʵ��� �س��´�.

int H[100]; //�迭�� ũ�⸦ 100���� ũ��
int n = 0;  //���� key���� ���� ����
int i, key;
char  choice;

void insertItem(int key);
int removeMax();
void upHeap(int i);
void downHeap(int i);
void printHeap();


int main()
{
	H[0] = MAX_VAL; //�迭 ù��° �ε����� ����ū��

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
	int par = i / 2; //������ 2������ �θ� ���ϱ�����
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
	key = H[1];//�ε���1���� ���� ����ū���̱� ������
	H[1] = H[n];//�������ε����� key���� root�� �����ٳ���
	(n)--;     //������ key���� ����� ��ġ�� ����
	downHeap(1);//1�� �ε������� ��迭 �ϱ����ؼ� �����
	return key; //������ key���� ����(����ū ���� ���� �� root�� ����)
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