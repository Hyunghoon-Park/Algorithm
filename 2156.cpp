#include <iostream>
#include <algorithm>
using namespace std;

int drink[10001], dp[10001];
int n;
int main(){
    scanf("%d", &n);
    for(int i = 1; i <= n; i++){
        scanf("%d", &drink[i]);
    }
    dp[1] = drink[1];
    if(n == 1){
        printf("%d", dp[1]);
        return 0;
    }
    dp[2] = drink[1] + drink[2];
    if(n == 2){
        printf("%d", dp[2]);
        return 0;
    }
    for(int i = 3; i <= n; i++){
        dp[i] = max({drink[i] + dp[i-2], drink[i-1] + drink[i-2] + dp[i-4], drink[i] + drink[i-1] + dp[i-3]});
    }
    printf("%d", dp[n]);
    return 0;
}