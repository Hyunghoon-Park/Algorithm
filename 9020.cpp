#include <iostream>
#include <vector>

using namespace std;

int t, n;
bool arr[10001] = {false,};
vector<int> prime_number;

void eratosthenes(){                            //에라토스테네스의 체
    for(int j = 2; j <= 100; j++)
		if(arr[j] == false)
			for(int k = 2; j * k <= 10000; k++)
				arr[j*k] = true;
    for(int i = 2; i <= 10000; i++)
        if(arr[i] == false)
            prime_number.push_back(i);
}

int main(){
    scanf("%d", &t);
    eratosthenes();
    for(int i = 0; i < t; i++){
        scanf("%d", &n);
        int min_result = 10000;
        int a, b;
        int end_point;
        for(int j = 0; j < prime_number.size(); j++){
            for(int k = j; k < prime_number.size(); k++){
                if(n == prime_number[j] + prime_number[k]){
                    if(min_result > prime_number[k] - prime_number[j]){
                        min_result = prime_number[k] - prime_number[j];
                        a = prime_number[j];
                        b = prime_number[k];
                    }
                }
            }
        }
        printf("%d %d\n", a, b);
    }
}