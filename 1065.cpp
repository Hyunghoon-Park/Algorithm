#include<iostream>

using namespace std;
int n;
int result = 0;

int main(){
    int one, two, three;
    scanf("%d", &n);
    if(n < 100){
        result = n;
    }
    else{
        result += 99;
        for (int i = 100; i <= n; i++){
            three = i / 100;
            two = (i - three*100) / 10;
            one = i - three*100 - two*10;
            int tmp = three - two;
            if(tmp == two - one)
                result++;
        }
    }
    printf("%d", result);
    return 0;
}