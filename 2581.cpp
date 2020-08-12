#include <iostream>
using namespace std;
bool is_prime(int a);
int main() {
	int m, n, min = 0, sum = 0;
	scanf("%d %d", &m, &n);
	for (int i = m; i <= n; i++) {
		if (is_prime(i) == true) {
			sum += i;
			if (min == 0 || min == 1) {
				min = i;
			}
		}
	}
	if (min == 0)
		printf("-1");
	else {
		printf("%d\n", sum);
		printf("%d", min);
	}
	return 0;
}
bool is_prime(int a) {
	for (int i = 2; i < a; i++) {
		if (a % i == 0)
			return false;
	}
	return true;
}