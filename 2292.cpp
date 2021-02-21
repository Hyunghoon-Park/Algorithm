#include <iostream>

using namespace std;

int n, result = 1;

int main(){
    scanf("%d", &n);
    n -= 1;
    if(n == 0){
        printf("1");
        return 0;
    }
    while(1){
        n -= (result++*6);
        if(n <= 0)
            break;
    }
    printf("%d", result);
}