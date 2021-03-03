#include <iostream>

using namespace std;

int n, input, result = 0;

int main(){
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d", &input);
        int tmp = 0;
        for(int j = 1; j <= input; j++)
            if(input % j == 0)
                tmp++;
        if(tmp == 2)
            result++;
    }
    printf("%d", result);
}