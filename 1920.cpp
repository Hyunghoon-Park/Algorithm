#include <iostream>
#include <algorithm>
using namespace std;

int arr_n[100001] = { 0 };

int main() {
	int n, m;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr_n[i]);
	}
	sort(arr_n, arr_n + n);
	scanf("%d", &m);
	for (int i = 0; i < m; i++) {
		int tmp;
		scanf("%d", &tmp);
		if (binary_search(arr_n, arr_n + n, tmp))
			printf("1\n");
		else
			printf("0\n");
	}
	return 0;
}