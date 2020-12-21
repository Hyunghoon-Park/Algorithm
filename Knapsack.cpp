#include <iostream>
#define n 4
#define W 10
using namespace std;
int p[5] = {0,40,30,20,10};
int w[5] = {0,2,3,4,5};
char bestset[5];
int numbest;
int maxprofit = 0;
char include[5];

bool promising(int i, int profit, int weight){
    int j, k;
    int totweight;
    float bound;
    if(weight >= W)
        return false;
    else{
        j = i + 1;
        bound = profit;
        totweight = weight;
        while(j <= n && totweight + w[j] <= W) {
            totweight = totweight + w[j];
            bound = bound + p[j];
            j++;
        }
        k = j;
        if(k <= n)
            bound = bound + (W-totweight) * (p[k]/w[k]);
            return bound > maxprofit;
    }
}

void knapsack(int i, int profit, int weight){
    if(weight <= W && profit > maxprofit){
        maxprofit = profit;
        numbest = i;
        for(int j = 1; j < 5; j++)        
            bestset[j] = include[j];
    }
    if(promising(i, profit, weight)){
        include[i+1] = 'Y';
        knapsack(i+1, profit + p[i+1], weight + w[i+1]);
        include[i+1] = 'N';
        knapsack(i+1, profit, weight);
    }
}

int main(){
    int i = 0;
    int profit = 0;
    int weight = 0;
    knapsack(i,profit, weight);
    printf("Maxprofit : %d\n", maxprofit);
    printf("**Bestset 출력**\n");
    for(i = 1; i <= numbest; i++)
        printf("%d 번째 : %c\n", i, bestset[i]);
    return 0;
}