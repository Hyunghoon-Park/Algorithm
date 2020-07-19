#include <iostream>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int num;	//input num count
	int sum = 0;	//input num's sum 
	char ch;	// input num
	cin >> num;
	for (int i = 0; i < num; i++) {
		cin >> ch;
		sum += (ch - '0');
	}
	cout << sum << endl;
	return 0;
}
