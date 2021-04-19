#include <iostream>
#include <string>
#include <queue>
#include <algorithm>
#include <map>

using namespace std;

int n, k;
queue<pair<string, int>> q;

int_fast64_t bfs(string s){
    q.push({s,0});
    map<string, bool> visit;
    string result = s;
    sort(result.begin(), result.end());
    while(!q.empty()){
        string cur = q.front().first;
        int cnt = q.front().second;
        q.pop();
        if(cur == result)
            return cnt;
        if(!visit.count(cur)){
            visit[cur] = true;
            for(int j = 0; j <= n-k; j++){
                string temp = cur.substr(j, k);
                reverse(temp.begin(), temp.end());
                q.push({ cur.substr(0, j) + temp + cur.substr(j + k, cur.size()), cnt + 1 });
            }
        }
    }
    return -1;
}

int main(){
    scanf("%d %d", &n, &k);
    string s;
    for(int i = 0; i < n; i++){
        char c;
        cin >> c;
        s += c;
    }
    printf("%d", bfs(s));
}