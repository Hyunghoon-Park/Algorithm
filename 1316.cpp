#include <iostream>
#include <string>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int alpha_arr[101][27] = { 0 };	//alphabat arr
	int input_count;		//input word count
	int count = 0;		//correct word count
	string input_str;	//input word
	cin >> input_count;
	for (int i = 0; i < input_count; i++) {
		cin >> input_str;
		alpha_arr[i][input_str[0] - 97]++;
		count++;
		for (int j = 1; j < input_str.length(); j++) {
			if (input_str[j - 1] != input_str[j]) {
				alpha_arr[i][input_str[j] - 97]++;
			}
			if (alpha_arr[i][input_str[j] - 97] > 1) {
				count--;
				break;
			}
		}
	}
	cout << count;
	return 0;
}