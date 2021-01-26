#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct node{
    int parents;
    int left;
    int right;
    int depth;
    int width;
};
int n, tmp1, tmp2, tmp3, root, value = 1, result = 0;
vector<int> level[10001];
struct node nodes[10001];

void make_dept(int a){                              //자식노드가 -1이 아니면 부모노드의 depth에 +1
    if(nodes[a].left != -1){
        nodes[nodes[a].left].depth = nodes[a].depth + 1;
        make_dept(nodes[a].left);
    }
    if(nodes[a].right != -1){
        nodes[nodes[a].right].depth = nodes[a].depth + 1;
        make_dept(nodes[a].right);
    }
}

void make_width(int a){
    if(nodes[a].left != -1)
        make_width(nodes[a].left);
    nodes[a].width = value++;
    if(nodes[a].right != -1)
        make_width(nodes[a].right);

}

int main(){
    scanf("%d", &n);
    for(int i = 1; i <= n; i++){
        scanf("%d %d %d", &tmp1, &tmp2, &tmp3);
        nodes[tmp1].left = tmp2;                    //왼쪽
        nodes[tmp1].right = tmp3;                   //오른쪽
        nodes[tmp2].parents = tmp1;                 //왼쪽 자식의 부모
        nodes[tmp3].parents = tmp1;                 //오른쪽 자식의 부모
    }
    for(int i = 1; i <= n; i++){
        if(nodes[i].parents == 0)                   //부모가 0이면 root인 노드
            root = i;
    }
    nodes[root].depth = 1;                           //부모의 depth는 1
    make_dept(root);
    int value = 1;
    make_width(root);                                    //너비 구하기
    for(int i = 1; i <= n; i++)
        level[nodes[i].depth].push_back(nodes[i].width); //depth별 width저장
    int k = 1;
    for(int i = 1; i <= n; i++)
        if(level[i].size() > 0 && result < *max_element(level[i].begin(), level[i].end()) - *min_element(level[i].begin(), level[i].end())){
            result = *max_element(level[i].begin(), level[i].end()) - *min_element(level[i].begin(), level[i].end());
            k = i;
        }
    printf("%d %d", k, result+1);
}