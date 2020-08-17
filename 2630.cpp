#include <iostream>
using namespace std;

int paper[128][128];
int blue = 0, white = 0;
void divide(int i, int j, int size);
int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%d", &paper[i][j]);
		}
	}
	divide(0, 0, n);
	printf("%d\n%d", white, blue);
	return 0;
}
void divide(int i, int j, int size) {
	int tmp = paper[i][j];		//blue = 1, white = 0
	for (int m = i; m < i + size; m++) {
		for (int k = j; k < j + size; k++) {
			if (tmp != paper[m][k]) {
				divide(i, j, size / 2);
				divide(i + size / 2, j, size / 2);
				divide(i, j + size / 2, size / 2);
				divide(i + size / 2, j + size / 2, size / 2);
				return;
			}
		}
	}
	if (tmp == 1)
		blue++;
	else
		white++;
}