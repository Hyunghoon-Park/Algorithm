#include <iostream>
#include <algorithm>
using namespace std;

int n , m, k, result = 0;
string table[51];

int main(){
    scanf("%d %d", &n, &m);
    for(int i = 0; i < n; i++)
        cin >> table[i];
    scanf("%d", &k);
    for(int i = 0; i < n; i++){
        int cnt = 0;
        for(int j = 0; j < m; j++){
            if(table[i][j] == '0')
                cnt++;
        }
        int tmp = 0;
        if(k >= cnt && (k - cnt) % 2 == 0){
            for(int j = 0; j < n; j++){
                if(table[i] == table[j])
                    tmp++;
            }
        }
        result = max(result, tmp);
    }
    printf("%d", result);
}