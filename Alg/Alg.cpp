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

	for (i = 0; i < n; i++) {
		for (j = 0; j < n-1; j++) { //�� n-1�ΰ� ���������� for���� �������� ���������� ���� ū ���� �������� ���� �ʾƵ� �ȴ�.
			if (data[j] > data[j + 1]) {//�տ��ε����� �ִ� �����Ͱ��� �ڿ��ִ� ������ ū��� ���� ��ġ�� ����Ī���ش�
				tmp = data[j];
				data[j] = data[j + 1];
				data[j] = tmp;
			}
		}
	}

	for (k = 0; k < n; k++) {
		printf("%d", data[i]);
		printf(" ");
	}
	free(data);//��� ���� ������ �Ҵ�� data�� Ǯ���ش�.
	return 0;
}