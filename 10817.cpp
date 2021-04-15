#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int a, b, c;
vector<int> v;
int main(){
    scanf("%d %d %d", &a, &b, &c);
    v.push_back(a);
    v.push_back(b);
    v.push_back(c);
    sort(v.begin(), v.end());
    printf("%d", v[1]);
}