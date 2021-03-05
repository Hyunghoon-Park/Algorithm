#include <iostream>
#include <cmath>

using namespace std;

int n, root, m, N, cnt;  

int main() {

    while(1){
        scanf("%d", &n);
        if(!n)
            break;
        m = n + 1;
        N = n * 2;
        cnt = 0;
        for(int i = m; i <= N; i++){
            root = sqrt(i);
            if(root == 1 && i != 1){
                cnt++;
                continue;
        }
        
        if(i%2)             //n���� ũ�� 2���� �۰ų� ���� ���� Ȧ���� ���
            for(int j = 2; j <= root; j++){     
                if(!(i%j))
                    break;
                if(j == root)
                    cnt++;
            }
        }
    printf("%d\n", cnt);
    }  
}