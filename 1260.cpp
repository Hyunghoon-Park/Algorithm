#include <iostream>
#include <queue>
using namespace std;

int n, m, v, tmp1, tmp2;
int arr[1001][1001] = { 0 };
int check[1001] = { false };

void dfs(int v);
void bfs(int v);

int main() {
	scanf("%d %d %d", &n, &m, &v);
	for (int i = 0; i < m; i++) {
		scanf("%d %d", &tmp1, &tmp2);
		arr[tmp1][tmp2] = 1;
		arr[tmp2][tmp1] = 1;
	}
	dfs(v);
	printf("\n"); 
	fill(&check[0], &check[0] + 1001, false);
	bfs(v);
	return 0;
}
void dfs(int v){
	printf("%d", v);
	check[v] = true;
	for(int i = 1; i <= n; i++){
		if(!check[i] && arr[v][i])
			dfs(i);
	}
}
void bfs(int v){
	queue<int> q;
	q.push(v);
	check[v] = true;
	while(!q.empty()){
		v = q.front();
		q.pop();
		printf("%d", v);
		for(int i = 1; i <= n; i++){
			if(!check[i] && arr[v][i]){
				q.push(i);
				check[i] = true;
			}
		}
	}
}