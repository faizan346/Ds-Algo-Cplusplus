#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    // int ocMask = ~n;
    // int tcMask = ocMask + 1; // two's complement is -n itself
    // int rmb = n & tcMask; // rmb = n & (~n + 1);
    int rsb = n & -n;
    string s = "";
    while(rsb) {
        s = (char)(rsb%2 + '0') + s;
        rsb = rsb/2;
    }
    cout << s << endl;
    return 0;
}