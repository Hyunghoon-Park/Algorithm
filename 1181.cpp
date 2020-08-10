#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
vector<string> v;

bool compare(string a, string b) {
	if (a.length() != b.length()) {
		return a.length() < b.length();
	}
	else {
		return a < b;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	string str;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> str;
		v.push_back(str);
	}
	sort(v.begin(), v.end(), compare);
	cout << v[0] << endl;
	for (int i = 1; i < n; i++) {
		if (v[i - 1].compare(v[i]) != 0)
			cout << v[i] << endl;
	}
	return 0;
}