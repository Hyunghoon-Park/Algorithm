#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
int main() {
	string str1, str2;
	cin >> str1 >> str2; 
	reverse(str1.begin(), str1.end());
	reverse(str2.begin(), str2.end());
	if (str1[0] > str2[0]) {
		cout << str1;
	}
	else if (str1[0] < str2[0]) {
		cout << str2;
	}
	else {
		if (str1[1] > str2[1]) {
			cout << str1;
		}
		else if (str1[1] < str2[1]) {
			cout << str2;
		}
		else {
			if (str1[2] > str2[2]) {
				cout << str1;
			}
			else {
				cout << str2;
			}
		}
	}
	return 0;
}