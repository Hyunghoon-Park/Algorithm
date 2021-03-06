#include <iostream>

using namespace std;

int n;
int fibonacci[21];

int main(){
    scanf("%d", &n);
    fibonacci[0] = 1;
    fibonacci[1] = 1;
    for(int i = 2; i < 21; i++)
        fibonacci[i] = fibonacci[i-1] + fibonacci[i-2];
    printf("%d", fibonacci[n-1]);
}