#include <iostream>
using namespace std;

int n, m;
int arr[9] = { 0 };
bool visit[9] = { false };
void dfs(int cnt) {
	if (cnt == m) {
		int check = 0;
		for (int i = 1; i < m; i++) {
			if (arr[i - 1] > arr[i]) {
				check++;
			}
		}
		if (check == 0) {
			for (int i = 0; i < m; i++) {
				printf("%d ", arr[i]);
			}
			printf("\n");
		}
	}
	else {
		for (int i = 1; i <= n; i++) {
			if (visit[i] == false) {
				visit[i] = true;
				arr[cnt] = i;
				dfs(cnt + 1);
				visit[i] = false;
			}
		}
	}
}

int main() {
	scanf("%d %d", &n, &m);
	dfs(0);
	return 0;
}