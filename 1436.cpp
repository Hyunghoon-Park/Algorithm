#include <iostream>
#include <string>
using namespace std;
int n, num = 666, count = 0;
int main(){
    scanf("%d", &n);
    while(count < n){
        int tmp = num;
        while(tmp > 665){
            if((tmp % 1000) == 666){
                count++;
                break;
            }
            tmp /= 10;
        }
        num++;
    }
    printf("%d", num-1);
}