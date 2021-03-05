#include <iostream>

using namespace std;

int t, k, n;
int apt[15][15];

int main(){
    scanf("%d", &t);
    for(int i = 0; i <= 15; i++)     //0ÃþÀÇ iÈ£´Â i¸í
        apt[0][i] = i;
    for(int x = 0; x < t; x++){
        scanf("%d %d", &k, &n);
        for(int i = 1; i <= k; i++){
            int sum = 0;
            for(int j = 1; j <= n; j++){
                sum += apt[i-1][j];
                apt[i][j] = sum;
            }
        }
        printf("%d\n", apt[k][n]);
    }
}