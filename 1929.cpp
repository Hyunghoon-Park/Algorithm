#include <iostream>
#include <stdio.h>
#include <math.h>
using namespace std;
bool arr[1000002] = { false };
int main() {
	//ios_base::sync_with_stdio(false);
	//cin.tie(NULL);
	//cout.tie(NULL);
	int M;	//M이상
	int N;	//N이하
	cin >> M >> N;
	arr[1] =  true;	
	for (int j = 2; j <= sqrt(N); j++) {
		if (arr[j] == false) {
			for (int k = 2; j * k <= N; k++) {
				arr[j*k] = true;
			}
		}
	}
	for (int i = M; i <= N; i++) {
		if (arr[i] == false)
			printf("%d\n",i);
	}
	return 0;
}