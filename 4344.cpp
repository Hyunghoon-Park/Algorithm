#include <iostream>
#include <memory.h>

using namespace std;

int main() {
    int T;
    int stud[1000];
    cin >> T;
    for(int i=0; i<T; i++){
        int N;
        cin >> N;
        memset(stud, 0, sizeof(stud));
        int mean = 0;
        for(int j=0; j<N; j++){
            cin >> stud[j];
            mean += stud[j];
        }
        mean = mean/N;
        int cnt=0;
        for(int j=0; j<N; j++){
            if(stud[j]>mean) {
                cnt++;
            }
        }
        cout << fixed;
        cout.precision(3);
        cout << 100*cnt/(double)N << "%" << endl;
    }
    return 0;
}