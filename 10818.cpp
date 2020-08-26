#include <iostream>

using namespace std;

int main(){
	
	int n;
	scanf("%d", &n);
	
	int num[n+1];
	int min = 1000000;
	int max = -1000000;
	
	for(int i=0; i<n; i++){
		scanf("%d", &num[i]);
		if(min > num[i]){
			min = num[i];
		}
		if(max < num[i]){
			max = num[i];
		}
	}
	printf("%d %d", min, max);
	return 0;
}
