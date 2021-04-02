using namespace std;
 
long long cal_gcd(int a, int b){
    long long c;
    while(b != 0){
        c = a % b;
        a = b;
        b = c;
    }
    return a;
}
 
long long solution(int w,int h) {
    long long answer = 1;
    long long all = (long long)w * (long long)h; 
    long long gcd = cal_gcd(w,h);
    answer = all - ((w+h)/gcd - 1) * gcd;
    return answer;
}