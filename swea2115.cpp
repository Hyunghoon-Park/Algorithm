#include<iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n, m, c, value;
int honey[10][10];
bool visit[10][10];
vector<int> work[2];

int money(int worker, int idx, int sum, int result){
    if(sum > c) 
        return -1;
    if(idx == m)
        return result;
    int newresult = work[worker][idx] * work[worker][idx];
    int rt = 0;
 
    int tmp1 = money(worker, idx + 1, sum + work[worker][idx], result+newresult);
    int tmp2 = money(worker, idx + 1, sum, result);
    if(tmp1 != -1) 
        rt = tmp1;
    if(tmp2 != -1 && rt < tmp2) 
        rt = tmp2;
    return rt;
}

void select_honey(int x, int idx){
    if(idx == 2){
        int tmp = money(0,0,0,0) + money(1,0,0,0);
        value = max(value, tmp);
        return;
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j <= n-m; j++){
            bool tmp = true;
            for(int k = 0; k < m; k++){
                if(visit[i][j+k] == true){
                    tmp = false;
                    break;
                }
            }
            if(tmp == false)            //이미 방문된 꿀통이라면
                continue;
            for(int k = 0; k < m; k++){
                visit[i][j+k] = true;
                work[idx].push_back(honey[i][j+k]);
            }
            select_honey(i, idx+1);
            for(int k = 0; k < m; k++){
                visit[i][j+k] = false;
                work[idx].pop_back();
            }
        }
    }
}

int main(int argc, char** argv){
	int test_case;
	int T;
	cin>>T;
	for(test_case = 1; test_case <= T; ++test_case){
        scanf("%d %d %d", &n, &m, &c);
        fill(&visit[0][0], &visit[9][10], false);
        value = 0;
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                scanf("%d", &honey[i][j]);   
        select_honey(0,0);        
        printf("#%d %d\n",test_case, value);
	}
	return 0;
}