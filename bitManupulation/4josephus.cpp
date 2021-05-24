#include<bits/stdc++.h>
using namespace std;

int highestPowerOfTwo(int n) {
    int powerOfTwo = 1;
    while(powerOfTwo * 2 <= n) {
        powerOfTwo *= 2;
    }
    return powerOfTwo;
}

int josephus(int n) {
    int powerOfTwo = highestPowerOfTwo(n);
    int l = n - powerOfTwo;
    int ans = 2 * l + 1;
    return ans;
}

int main() {
    int n;
    cin >> n;
    cout << josephus(n) << endl;
    return 0;
}