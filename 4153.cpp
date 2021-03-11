#include <iostream>
#include <algorithm>

using namespace std;

int a, b, c, max_value;

int main(){
    while(1){
        scanf("%d %d %d", &a, &b, &c);
        if(a == 0 && b == 0 && c == 0)
            break;
        a *= a;
        b *= b;
        c *= c;
        max_value = max(a,b);
        max_value = max(max_value, c);
        if(max_value == a){
            if(a == (b+c))
                printf("right\n");
            else
                printf("wrong\n");
        }
        else if(max_value == b){
            if(b == (a+c))
                printf("right\n");
            else
                printf("wrong\n");
        }
        else{
            if(c == (b+a))
                printf("right\n");
            else
                printf("wrong\n");
        }
    }
}