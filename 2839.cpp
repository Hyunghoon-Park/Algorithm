#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int weight;	//����
	int count = 0;	//���
	cin >> weight;
	while (weight > 2) {
		if (weight % 5 == 0) {
			weight -= 5;
			count++;
		}
		else if (weight % 3 == 0) {
			weight -= 3;
			count++;
		}
		else {
			weight -= 5;
			count++;
		}
		if (weight != 0 && weight < 3) {
			count = -1;
			break;
		}
	}
	cout << count;
	return 0;
} 