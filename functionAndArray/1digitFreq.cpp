#include<bits/stdc++.h>
using namespace std;

int digitFreq(int n, int d) {
    int count = 0;
    while(n) {
        int dig = n%10;
        n = n/10;
        if(dig == d) {
            count++;
        }
    }
    return count;
}

int main() {
    int n, d;
    cin >> n >> d;
    cout << digitFreq(n, d) << endl;
    return 0;
}