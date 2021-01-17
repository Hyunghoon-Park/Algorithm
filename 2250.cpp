#include <iostream>
#include <algorithm>

using namespace std;

int N, nodeIdx; //N과 노드의 위치
int node[10001]; //루트 찾기 위해
int low[10001];
int high[10001];
pair<int, int> tree[10001];

int main(){
    scanf("%d", &n);

    for (int i = 0; i < MAX; i++)
        low[i] = INF;
    for(int i = 0; i < n; i++){
        scanf("%d %d %d", &parents, &left, &right);
        node[parents]++;
        if(left != -1)
            node[left]++;
        tree[parents].push_back(left);
        if(right != -1)
            node[right]++;
        tree[parents].push_back(right);
    }
    for(int i = 0; i < n; i++)
        if(node[i] == 1)
            root = i;           //root를 구함
    checklevel(root,0);
}