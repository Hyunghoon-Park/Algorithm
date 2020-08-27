#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<vector<int>> v;
vector<vector<bool>> visit;
int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};
int n, tmp, range;

void bfs(int x, int y);
int main() {
	scanf("%d", &n);
	v.resize(n+2);
	visit.resize(n+2);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			scanf("%d", &tmp);
			v[i].push_back(tmp);
		}
	}
	tmp = 0;
	bfs(1,1); 
	return 0;
}

void bfs(int x, int y){

}