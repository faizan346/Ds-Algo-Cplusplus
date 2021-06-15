#include<bits/stdc++.h>
using namespace std;
// 5 - 0b101
// A - 1010 hex
// 5 - 0101 hex

int main() {
    int n;
    cin >> n;
    int offEven = 0x55555555;  // 01010101010101010101010101010101
    int offOdd = 0xAAAAAAAA;   // 10101010101010101010101010101010
    int odds = n & offEven;
    int evens = n & offOdd;
    // shift odd to left to make even and even to right to make odd
    n = (odds << 1) | (evens >> 1);
    cout << n << endl;
    return 0;
}