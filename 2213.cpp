#include <iostream>
using namespace std;
    int n, result = 1000000;
int main(){
    scanf("%d", &n);
    for(int i = 1; i < n; i++){
        int sum = i;
        int tmp = i;
        while(tmp){
            sum += (tmp % 10);
            tmp /= 10;
        }
        if(n == sum){
            printf("%d", i);
            return 0;
        }
    }
    printf("0");
    return 0;
}