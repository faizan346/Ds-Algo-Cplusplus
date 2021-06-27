#include<bits/stdc++.h>
using namespace std;


long long maxPowerOf2(int n) {
    long long res = -1;
    while(n) {
        n = n >> 1;
        res++;
    }
    return res;
}

long long solve(int n) {
    if(n == 0) return 0;
    long long mp2 = maxPowerOf2(n);
    long long res = 0;
    res = ((1 << (mp2-1)) * mp2) + (n - (1 << mp2) + 1) + solve(n - (1 << mp2));
    return res;
}

int main() {
    int n;
    cin >> n;
    cout << solve(n) << endl;
    return 0;
}