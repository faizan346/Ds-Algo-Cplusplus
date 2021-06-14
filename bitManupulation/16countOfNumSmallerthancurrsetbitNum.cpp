#include<bits/stdc++.h>
using namespace std;

int csb(long long n) { // count set bit
    int res = 0;
    while(n > 0) {
        n = n & (n-1);
        res++;
    }
    return res;
}

long long ncr(long long n, long long r) {
    if(r > n) return 0;
    if(r == n || r == 0) return 1;
    long long res = 1;
    for(long long i = 0; i < r; i++) {
        res *= n-i;
        res /= i+1;
    }
    return res;
    
}

long long solution(long long n, int setBits, int bitIndex) {
    if(bitIndex == 0) return 0;
    long long res = 0;
    long long mask = (1ll << bitIndex);
    if((n & mask) == 0) {
        res = solution(n, setBits, bitIndex-1);
    } else {
        long long res1 = solution(n, setBits - 1, bitIndex-1);
        long long res0 = ncr(bitIndex, setBits);
        res = res1 + res0;
    }
    
    return res; 
}

int main() {
    long long n;
    cin >> n;
    cout << solution(n, csb(n), 62) << endl;
    return 0;
}

