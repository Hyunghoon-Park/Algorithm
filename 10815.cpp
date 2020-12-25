#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
int m;
vector<int> v;

int main() {
  int tmp;
  scanf("%d", &n);
  for(int i = 0; i < n; i++){
    scanf("%d", &tmp);
    v.push_back(tmp);
  }
  sort(v.begin(), v.end());
  scanf("%d", &m);
  for(int i = 0; i < m; i++){
    scanf("%d", &tmp);
    if(binary_search(v.begin(), v.end(), tmp)){
      printf("1 ");
    }
    else{
      printf("0 ");
    }
  }
  return 0;
}