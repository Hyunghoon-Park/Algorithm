#include <iostream>
#include <vector>
#include <stack>
using namespace std;
stack<char> s;
int main(void) {
	char str[101];
	cin >> str;
	stack<char> s;
	for (int i = 0; str[i] != '\0'; i++) {
		char value = str[i];
		if (value <= 'Z' && 'A' <= value) 
            printf("%c", value);
		else if (value == '(') 
            s.push(value);
		else if (value == ')') {
			while (s.top() != '(') {
				printf("%c", s.top());
				s.pop();
			}
			s.pop();
		}
		else if (s.empty()) 
            s.push(value);
		else {
			while (!s.empty()) {
				if (s.top() == '(') {
					s.push(value);
					break;
				}
				else if (value == '+' || value == '-') {
						printf("%c", s.top());
						s.pop();
						continue;
				}
				else if (value == '*' || value == '/') {
					if (s.top() == '*' || s.top() == '/') {
						printf("%c", s.top());
						s.pop();
						continue;
					}
					else {
						s.push(value);
						break;
					}
				}
			}
			if (s.empty()) 
                s.push(value);
		}
	}
	while (!s.empty()) {
		printf("%c", s.top());
		s.pop();
	}
	printf("\n");
	return 0;
}