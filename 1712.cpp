#include <iostream>

using namespace std;

int a, b, c, count;

int main(){
    scanf("%d %d %d", &a, &b, &c);
    int value = c - b;
    if(value <= 0){
        printf("-1");
        return 0;
    }
    count = a / value;
    printf("%d", count + 1);
    return 0;
}