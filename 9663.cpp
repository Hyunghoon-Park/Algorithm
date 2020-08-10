#include <iostream>
using namespace std;

int arr[15];
int result = 0;
int n;
void N_queen(int tmp);
bool check_queen(int tmp);

int main() {
	scanf("%d", &n);
	N_queen(0);
	printf("%d", result);
	return 0;
}
void N_queen(int tmp) {
	if (tmp == n) {
		result++;
	}
	else {
		for (int i = 0; i < n; i++) {
			arr[tmp] = i;
			if (check_queen(tmp)) {
				N_queen(tmp + 1);
			}
		}
	}
}
bool check_queen(int tmp) {
	for (int i = 0; i < tmp; i++) {
		if ((tmp - i) == abs(arr[tmp] - arr[i]) || arr[tmp] == arr[i]) {
			return false;
		}
	}
	return true;
}