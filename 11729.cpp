#include <iostream>
#include <vector>

using namespace std;

int n;
vector<pair<int, int>> v;

void hanoi(int num, int from, int by, int to){
    if(num == 1){
        v.push_back({from, to});
    }
    else{
        hanoi(num-1, from, to, by);
        v.push_back({from, to});
        hanoi(num-1, by, from, to);
    }
}

int main(void){
    scanf("%d", &n);
    hanoi(n,1,2,3);
    printf("%d\n", v.size());
    for(int i = 0; i < v.size(); i++)
        printf("%d %d\n", v[i].first, v[i].second);
}