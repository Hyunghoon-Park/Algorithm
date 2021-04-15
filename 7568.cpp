#include <iostream>
#include <vector>

using namespace std;

int n, x, y;
vector<pair<int, int>> v;

int main(){
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d %d", &x, &y);
        v.push_back({x, y});
    }
    for(int i = 0; i < n; i++){
        int count = 1;
        for(int j = 0; j < n; j++)
            if(v[i].first < v[j].first && v[i].second < v[j].second)
                count++;
        printf("%d ", count);
    }
}