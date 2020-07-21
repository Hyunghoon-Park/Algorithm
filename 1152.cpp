#include <iostream>
#include <string>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	string input_str;	//input string
	int space_count = 0;	//count space
	int word_count = 0;		//count word
	getline(cin, input_str);
	for (int i = 0; i < input_str.length(); i++)
		if (input_str[i] == ' ')
			space_count++;
	if (input_str[0] == ' ')
		space_count--;
	if (input_str[input_str.length() - 1] == ' ')
		space_count--;
	word_count = space_count + 1;
	cout << word_count;
	return 0;
}