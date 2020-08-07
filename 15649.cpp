#include <iostream>
using namespace std;

int n, m;
int arr[9] = { 0 };
bool visited[9] = { false };
void dfs(int cnt);

int main() {
	scanf("%d %d", &n, &m);
	dfs(0);
}

void dfs(int cnt)
{
	if (cnt == m)
	{
		for (int i = 0; i < m; i++)
			printf("%d ", arr[i]);
		printf("\n");
		return;
	}
	for (int i = 1; i <= n; i++)
	{
		if (visited[i] == false)
		{
			visited[i] = true;
			arr[cnt] = i;
			dfs(cnt + 1);
			visited[i] = false;
		}
	}
}