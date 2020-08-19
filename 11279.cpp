#include <iostream>
#include <queue>

using namespace std;
priority_queue<int> pq;
int main() {
	int n, tmp;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &tmp);
		if (tmp == 0) {
			if (pq.empty()) {
				printf("0\n");
			}
			else {
				printf("%d\n", pq.top());
				pq.pop();
			}
		}
		else {
			pq.push(tmp);
		}
	}
	return 0;
}