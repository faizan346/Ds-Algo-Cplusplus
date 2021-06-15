#include<bits/stdc++.h>
using namespace std;

// 7n/8 ==> (8n - n)/8   
// power of 2 can use bits operation for multplication & division
// in division the bits before power of 2 are remainder and others are quotient
// 111001010100 divide by 8(power of 2 by 3) will give q = 1110010101, r = 100
// as  divide will shift to right and by subtracting the the shifted number to non shifted
// we can find the rem. that how we know the above case.

int main() {
    int n;
    cin >> n;
    int ans = ((n<<3) - n) >> 3;
    cout << ans << endl;
    
    return 0;
}