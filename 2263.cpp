#include <iostream>
#include <vector>
using namespace std;

int inorder[100001];
int postorder[100001];
int index[100001];
int n;

void preOrder(int ibegin, int iend, int pbegin, int pend){
  if(ibegin > iend || pbegin > pend)
    return;
  int root = postorder[pend];
  printf("%d ", root);
  preOrder(ibegin, index[root]-1, pbegin, pbegin +(index[root] - ibegin)-1);
  preOrder(index[root]+1, iend, pbegin +(index[root] - ibegin), pend-1);
  
}
int main(){
  int tmp;
  scanf("%d", &n);
  for(int i = 0; i < n; i++)
    scanf("%d", &inorder[i]);
  for(int i = 0; i < n; i++)
    scanf("%d", &postorder[i]);
  for(int i = 0; i < n; i++)
    index[inorder[i]] = i;
  preOrder(0,n-1,0,n-1);
  return 0;
}