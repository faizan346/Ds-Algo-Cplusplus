#include<bits/stdc++.h>
using namespace std;

void solve1(vector<int>& a, int n) {
    vector<int> b(32, 0); // count of on bits for position;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j <= 31; j++) {
            b[j] += ((a[i] & (1 << j)) ? 1 : 0);
        }
    }
    int ans = 0;
    for(int i = 0; i <= 31; i++) {
        if(b[i] % 3 != 0) {
            ans += (1 << i);
        }
    }
    cout << ans << endl;
}

void solve2(vector<int>& a, int n) {
    // b % 3 == 0, 1, 2
    // initially we take b3r0 all bits set as we assume the first number to be 0.
    // as it has 0 bit set it wont effect the result.
    int b3r0= ~0, b3r1 = 0, b3r2 = 0;
    for(int i = 0; i < n; i++) {
        // switching off reoccuring bits
        int toggleMask0 = (b3r0 & a[i]);
        b3r0 = (b3r0 ^ toggleMask0); // extra bits
        int toggleMask1 = (b3r1 & a[i]);
        b3r1 = (b3r1 ^ toggleMask1);
        int toggleMask2 = (b3r2 & a[i]);
        b3r2 = (b3r2 ^ toggleMask2);
        //switching on the bits which are adding one to rem of prev remainders
        b3r1 = (b3r1 | toggleMask0);
        b3r2 = (b3r2 | toggleMask1);
        b3r0 = (b3r0 | toggleMask2);

    }
    cout << b3r1 << endl;
}

int main() {
    int n;
    cin >> n;
    vector<int> a(n, 0);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    //solve1(a, n);
    solve2(a, n);
    return 0;
}