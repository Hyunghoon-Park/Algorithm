#include <iostream>

using namespace std;

int sudoku[10][10]; //스도쿠 판
int col[10][10];    //행
int row[10][10];    //열
int box[10][10];    //네모박스
int main(){
    for(int i = 1; i < 10; i++){
        for(int j = 1; j < 10; j++){
            scanf("%d", sudoku[i][j]);
        }
    }
    return 0;
}