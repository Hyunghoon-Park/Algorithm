#include <iostream>
#include <algorithm>
using namespace std;

int arr[1001];
int main() {
	int n, tmp;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &tmp);
		arr[i] = tmp;
	}
	for (int i = 1; i < n; i++) {
		for (int j = 1; j < n; j++) {
			if (arr[j - 1] > arr[j])
				swap(arr[j - 1], arr[j]);
		}
	}
	for (int i = 0; i < n; i++)
		printf("%d\n", arr[i]);
	return 0;
}