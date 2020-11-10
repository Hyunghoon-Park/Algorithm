#include <iostream>
#include <vector>

using namespace std;
vector<vector<int>> v;
vector<bool> visit;
int result = 0;
void dfs(int a);
int main() {
	int n, m, tmp1, tmp2;
	scanf("%d %d", &n, &m);
	v.resize(n + 1);
	visit.resize(n + 1);
	for (int i = 0; i < m; i++) {
		scanf("%d %d", &tmp1, &tmp2);
		v[tmp1].push_back(tmp2);
		v[tmp2].push_back(tmp1);
	}
	dfs(1);
	printf("%d", result - 1);
	return 0;
}

void dfs(int a){
	result++;
	visit[a] = true;
	for(int i = 0; i < v[a].size(); i++){
		if(!visit[v[a][i]])
			dfs(v[a][i]);
	}
}