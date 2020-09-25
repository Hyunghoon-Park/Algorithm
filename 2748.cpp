#include <iostream>
#include <vector>
using namespace std;

vector<long long> v;
int main(){
    int n;
    v.push_back(0); 
    v.push_back(1);
    scanf("%d", &n);
    for(int i = 2; i <= n; i++){
        v.push_back(v[i-1] + v[i-2]);
    }
    printf("%lld", v[n]);
    return 0;
}
