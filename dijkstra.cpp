#include <iostream>
#include <algorithm>
#define MAX 100
using namespace std;

int W[5][5] = {{0,7,4,6,1},{MAX,0,MAX,MAX,MAX},{MAX,2,0,5,MAX},{MAX,3,MAX,0,MAX},{MAX,MAX,MAX,1,0}};
int F[5][5] = {0};
int touch[5];
int length[5];
int min_length(){
    int tmp = 100;
    int k;
    for(int i = 1; i < 5; i++){
        if(length[i] > 0 && tmp > length[i]){
            tmp = length[i];
            k = i;
        }
    }
    return k;
}
void change_len_to(int a, int num){
    bool change = false;
    for(int i = 1; i < 5; i++){
        if(length[i] != -1 && length[i] > (a + W[num][i])){
            length[i] = a + W[num][i];
            F[num][i] = W[num][i];
            touch[i] = num;
            change= true;
        }
    }
    if(change == false){
        F[touch[num]-1][num] = W[touch[num]-1][num];
    }
}
void dijkstra(int n){
    int tmp_val, tmp_num;
    touch[0] = 1;
    length[0] = -1;
    for(int i = 1; i < 5; i++){
        touch[i] = 1;
        length[i] = W[0][i];
    }
    F[0][min_length()] = W[0][min_length()];
    for(int i = 0; i < 3; i++){
        tmp_val = length[min_length()];
        tmp_num = min_length();
        length[min_length()] = -1;
        change_len_to(tmp_val, tmp_num);
    }
}
void printF(){
    printf("*** F ¹è¿­ ***\n");
        for(int i = 0; i < 5; i++){
            for(int j = 0; j < 5; j++){
                if(F[i][j] != 0)
                    printf("V%d --> V%d    %d\n", i+1, j+1, F[i][j]);
        }
    }
}

int main(){
    dijkstra(5);
    printF();
    return 0;
}