#include <iostream>  

using namespace std;

int main(void)
{
	int N;
	cin >> N;
	
	if (N > 1000)
		return -1;
	
	float score[1000];
	for (int i = 0; i < N; ++i)
	{
		cin >> score[i];
	}

	int max=0;

	for (int i = 0; i < N; ++i) 
		if (score[i] > max)
			max = score[i];
		

	for (int i = 0; i < N; ++i) 
		score[i] = score[i] / max * 100;
		

	float total = 0;
	for (int i = 0; i < N; ++i)
		total += score[i];

	cout << fixed;
	cout.precision(2);
	cout << total / N << endl;

	return 0;


}