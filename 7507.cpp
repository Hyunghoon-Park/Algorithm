#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n, m, d, s, e, max_day = 0;

bool compare(pair<int, int> p1, pair<int, int> p2){       
    if(p1.second == p2.second)
        return p1.first < p2.first;
    else
        return p1.second < p2.second;
}

int main(){
    scanf("%d", &n);
    for(int z = 1; z <= n; z++){
        vector<pair<int, int>> v[50000];
        scanf("%d", &m);
        for(int i = 0; i < m; i++){             //날자 별 s,e push
            scanf("%d %d %d", &d, &s, &e);
            v[d].push_back({s,e});
            max_day = max(max_day, d);
        }
        int sum = 0;
        for(int i = 0; i <= max_day; i++){
            int e_time = 0;         //경기 끝나는 시간
            if(v[i].size() > 0){
                sort(v[i].begin(), v[i].end(), compare);       //끝나는 시간으로 정렬, 같으면 시작순
                for(int j = 0; j < v[i].size(); j++){
                    if(e_time <= v[i][j].first){
                        e_time = v[i][j].second;
                        sum++;
                    }
                }
            }
        }
        printf("Scenario #%d:\n%d\n\n", z, sum);
    }
}