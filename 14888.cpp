#include <iostream>
#include <algorithm>
using namespace std;

void minmax_check(int i);
void dfs(int pl, int mi, int mu, int di, int sum, int cnt);

int MIN = 1000000001;
int MAX = -1000000001;
int arr[12];
int op[5];	//+는 [0] -는[1] *는[2] /는[3]
int n;

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &arr[i]);
	for (int i = 0; i < 4; i++)
		scanf("%d", &op[i]);
	dfs(op[0], op[1], op[2], op[3], arr[0], 1);
	printf("%d\n%d", MAX, MIN);
	return 0;
}
void minmax_check(int i) {
	MAX = max(MAX, i);
	MIN = min(MIN, i);
}
void dfs(int pl, int mi, int mu, int di, int sum, int cnt) {
	if (cnt == n) {
		minmax_check(sum);
	}
	else {
		if (pl > 0)
			dfs(pl - 1, mi, mu, di, sum + arr[cnt], cnt + 1);
		if (mi > 0)
			dfs(pl, mi - 1, mu, di, sum - arr[cnt], cnt + 1);
		if (mu > 0)
			dfs(pl, mi, mu - 1, di, sum * arr[cnt], cnt + 1);
		if (di > 0)
			dfs(pl, mi, mu, di - 1, sum / arr[cnt], cnt + 1);
	}
}