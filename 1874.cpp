#include <iostream>
#include <stack>
#include <queue>
#include <vector>

using namespace std;

stack<int> s;
queue<int> q;
vector<char> v;

int main() {
	int n, tmp;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &tmp);
		q.push(tmp);
	}
	tmp = 0;
	for (int i = 1; i <= n; i++) {
		v.push_back('+');
		s.push(i);
		if (q.front() == s.top()) {
			while (s.size() > 0 && q.front() == s.top()) {
				v.push_back('-');
				s.pop();
				q.pop();
			}
		}
	}
	if (s.size() != 0) {
		printf("NO");
	}
	else {
		for (int i = 0; i < v.size(); i++) {
			printf("%c\n", v[i]);
		}
	}

	return 0;
}
