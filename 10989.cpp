#include <iostream>
using namespace std;
int arr[10002];
int main() {
	int n, tmp;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &tmp);
		arr[tmp]++;
	}
	for (int i = 1; i <= 10000; i++) {
		if (arr[i] > 0) {
			printf("%d\n", i);
			arr[i--]--;
		}
	}
	return 0;
}