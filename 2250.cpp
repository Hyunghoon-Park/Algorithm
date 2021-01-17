#include <iostream>
#include <algorithm>

using namespace std;

int N, nodeIdx; //N�� ����� ��ġ
int node[10001]; //��Ʈ ã�� ����
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
            root = i;           //root�� ����
    checklevel(root,0);
}