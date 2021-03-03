#include <iostream>

using namespace std;

int t, h, w, n;

int main(){
    scanf("%d", &t);
    for(int i = 0; i <t; i++){
        scanf("%d %d %d", &h, &w, &n);
        int y = n % h;
        int x = n / h;
        if(y != 0)
            printf("%d\n", y*100 + x+1);
        else                                //꼭대기 층일 때
            printf("%d\n", h*100 + x);
    }
}