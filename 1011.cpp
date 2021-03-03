#include <iostream>
#include <cmath>
using namespace std;

int t, x, y;

int main(){
    scanf("%d", &t);
    for(int i = 0; i < t; i++){
        scanf("%d %d", &x, &y);
        long long a = 1;
        while(a * a <= (y-x))
            a++;
        a--;
        long long b = (y-x) - (a*a);
        b = (long long)ceil((double)b / (double)a);
        printf("%d\n", a * 2 - 1 + b);
    }
}