#include <iostream> 

using namespace std;

int n, m, x, y; 
int input[51][51]; 
int result = 0; 
int direction; //북, 동, 남, 서 
int dx[4] = { -1, 0, 1, 0 }; 
int dy[4] = { 0, 1, 0, -1 }; 
int main(){
    scanf("%d %d %d %d %d", &n, &m, &x, &y, &direction);
    for(int i = 0; i < n; i++) 
        for(int j = 0; j < m; j++)
            scanf("%d", &input[i][j]);
    while(1){
        if(input[x][y] == 0){
            input[x][y] = 2;
            result++; 
        } 
        int nextStep = 0; 
        for(int i = 0; i < 4; i++){ 
            direction = (direction + 3) % 4; // 왼쪽 방향으로 전환 
            int xx = x + dx[direction]; 
            int yy = y + dy[direction]; 
            if(input[xx][yy] == 0){
                x = xx;
                y = yy; 
                nextStep = 1; 
                break; 
            }
        } 
        if(nextStep == 1)
            continue; 
        int newDirection = (direction + 2) % 4; // 후진 
        x = x + dx[newDirection]; 
        y = y + dy[newDirection]; 
        if(input[x][y] == 1) 
            break; 
    }
    printf("%d", result);
}