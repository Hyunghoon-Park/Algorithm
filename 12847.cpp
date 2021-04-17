#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
long long tmp, max_value = 0;
vector<long long> v;
int main(){
    scanf("%d %d", &n, &m);
    for(int i = 0; i < n; i++){
        scanf("%lld", &tmp);
        v.push_back(tmp);
    }
    long long a = 0;
    for(int i = 0; i < n; i++){
        a += v[i];
        if(i >= m)
            a -= v[i-m];
        max_value = max(max_value, a);
    }
    printf("%lld", max_value);
}