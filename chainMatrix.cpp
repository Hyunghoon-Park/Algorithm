#include <iostream>
#include <algorithm>
#define N 6
#define MAX 2134565789
using namespace std;

int M[N+1][N+1] = {0};
int P[N+1][N+1] = {0};
int d[N+2] = {5,2,3,4,6,7,8};
int minmult(int d[], int P[N+1][N+1]);
void order(int i, int j);
void printm(){
    printf("M\n");
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= N; j++){
            printf("%3d ", M[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}
void printp(){
    printf("P\n");
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= N; j++){
            printf("%3d ", P[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}
int main(){
    printf("Chained Matrix Multiplication °á°ú : %d\n", minmult(d, P));
    printf("Order : "); 
    order(1,6);
    return 0;
}
int minmult(int d[], int P[N+1][N+1]){
    int i, j, k, diagonal, tmp;
    for(i = 1; i <= N; i++){
        M[i][i] = 0;
    }
    for(int i = 1; i < N; i++){
        for(int j = i+1; j <= N; j++){
            M[i][j] = MAX;
        }
    }
    for(diagonal=1; diagonal<=N-1; diagonal++)
		for (i = 1; i <= N - diagonal; i++) {
			j = i + diagonal;
			for (k = i; k <= j - 1; k++) {
				tmp = M[i][k] + M[k + 1][j] + d[i - 1] * d[k] * d[j];
				if (M[i][j] > tmp) {
					M[i][j] = tmp;
					P[i][j] = k;
				}
			}
            printm();
            printp();
		}
    return M[1][N];
}
void order(int i, int j) {
	int k;
	if (i == j)
		cout << "A" << i;
	else {
		k = P[i][j];
		cout << "(";
		order(i, k);
		order(k + 1, j);
		cout << ")";
	}
}