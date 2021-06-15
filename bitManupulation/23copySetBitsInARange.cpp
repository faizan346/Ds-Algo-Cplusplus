#include<bits/stdc++.h>
using namespace std;

void binaryToString(int n) {
    string s = "";
    while(n) {
        s = to_string(n % 2) + s;
        n = n/2;
    }
    cout << s << endl;
}

int main() {
    int a, b, l, r;
    cin >> a >> b >> l >> r;
    //faizan ans
    // for(int i = l-1; i < r; i++) {
    //     int mask = 1 << i;
    //     if((a & mask) != 0) {
    //         b = b | mask;
    //     }
    // }
    // after watching video by sir
    int mask = 1 << (r-l+1);    // 000010000   r=5,l=2
    mask = mask-1;              // 000001111
    mask = mask << (l-1);       // 000111100
    mask = a & mask; // gives set bit in range
    b = b | mask;  // set bits in range
    cout << b << endl;
    return 0;
}