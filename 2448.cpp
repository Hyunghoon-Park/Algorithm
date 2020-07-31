#include <iostream>
#include <algorithm>
using namespace std;
char arr[3100][6200];
void star(int x, int y, int z);
int main() {
	int N;
	scanf("%d", &N);
	fill(&arr[0][0], &arr[0][0] + 3100 * 6200, ' ');
	star(0, N - 1, N);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N * 2; j++) {
			printf("%c", arr[i][j]);
		}
		printf("\n");
	}
	return 0;
}
void star(int x, int y, int z) {
	if (z != 3) {
		star(x, y , z / 2);
		star(x + z / 2, y - z / 2, z / 2);
		star(x + z / 2, y + z / 2, z / 2);
	}
	else {
		arr[x][y] = '*';
		arr[x + 1][y - 1] = '*';
		arr[x + 1][y + 1] = '*';
		for (int i = -2; i <= 2; i++)
			arr[x + 2][y + i] = '*';
	}
}