#include<stdio.h>
#include <math.h>

#define N 8
int cols[N + 1];
int i, j;
bool promising(int level);

bool queens(int level) {
	if (promising(level)==false) return false;
	else if (level == N) {
		for (int i = 1; i < N; i++) {
			printf("%d", cols[i]);
			return true;
		}
		for (int i = 1; i <= N; i++) {
			cols[level + 1] = i;
			if (queens(level + 1))
				return true;
		}
		return false;
	}
}

bool promising(int level) {
	for (int i = 1; i < level;i++) 
	{
		if (cols[i] == cols[level]) 
		{
			return false; 
		}
		else if (level - i == abs(cols[level] - cols[i])) 
		{
			return false;
		}
	}
	return true;
}

int main() {
	queens(0);
}



