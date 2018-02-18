#include<stdio.h>

int BinarySearch(int nArray[], int begin, int end, int target);

int main()
{
	int nArray[] = { 1,3,5,7,9,11,13 };
	int result;

	result = BinarySearch(nArray, 0, sizeof(nArray) / sizeof(int) - 1, 7);

	if (result==-1) {
		printf("찾는 값이 없습니다");
	}
	else {
		for (int i = 0; i < sizeof(nArray) / sizeof(int); i++) {
			printf("%d", nArray[i]);
		}
		printf("\n%d 번쨰 배열 요소에 있습니다.", result);
	}
	return 0;
}

// 바이너리서치
int BinarySearch(int nArray[],int begin,int end,int target)
{
	int mid=0;
	if (begin > end) {
		return -1;
	}
	mid = (begin + end) / 2;

	if (nArray[mid] == target) {
		return mid;
	}
	else if (target < nArray[mid]) {
		return BinarySearch(nArray, begin, mid - 1, target);
	}
	else {
		return BinarySearch(nArray, mid+1, end, target);
	}
}

