#include <iostream>

using namespace std;

int n, l, r;
int contry[51][51];
bool visit[51][51];
int dy[4] = {1,0,0,-1};
int dx[4] = {0,1,-1,0};
bool roop = true;

void bfs(){

}

int main(){
    scanf("%d %d %d", &n, &l, &r);
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            scanf("%d", &contry[i][j]);
    while(roop){
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                bfs();
            }
        }

    }
}