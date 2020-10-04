#include<stdio.h>
int main(){
    int n,init, count = 0;
    scanf("%d", &n);
    init = n;
    int a, b, c, d;
    do {
        a = n/10;
        b = n%10;
        c = (a+b)/10;
        d = (a+b)%10;
        n = b*10 + d;
        count++;
    }while(n != init);
    printf("%d", count);
}