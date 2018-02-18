#include<stdio.h>

int main() {
	int tmp;// 임시로 데이터를 저장할 변수
	int k;// 입력값만큼 배열을 생성하기위한 변수
	int i, j;//배열의 각각 인덱스 비교를 하기위한 변수
	int *data; //배열의 크기를 동적할당하기 위한 변수
	int n; //사용자가 입력개수

	scanf("%s", &n);
	data = (int*)malloc(sizeof(int)*n);//data배열에 n만큼 동적할당

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
	free(data);//모든 일이 끝난후 할당된 data를 풀어준다.
	return 0;
}