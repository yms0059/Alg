#include<stdio.h>

int main() {
	int tmp;// �ӽ÷� �����͸� ������ ����
	int k;// �Է°���ŭ �迭�� �����ϱ����� ����
	int i, j;//�迭�� ���� �ε��� �񱳸� �ϱ����� ����
	int *data; //�迭�� ũ�⸦ �����Ҵ��ϱ� ���� ����
	int n; //����ڰ� �Է°���

	scanf("%s", &n);
	data = (int*)malloc(sizeof(int)*n);//data�迭�� n��ŭ �����Ҵ�

	for (k = 0; k < n; k++) {
		scanf("%d", &data[i]);
	}

	for (i = 1; i<n; i++)
	{
		temp = data[j];
		j = i - 1;
		while (j >= 0 && data[j] > tmp)
		{
			data[j + 1] = data[j];
			j = j - 1;
		}
		data[j + 1] = tmp;
	}

	for (k = 0; k < n; k++) {
		printf("%d", data[i]);
		printf(" ");
	}
	free(data);//��� ���� ������ �Ҵ�� data�� Ǯ���ش�.
	return 0;
}