#include<bits/stdc++.h>
using namespace std;

int getRev(int n) {
    int res = 0;
    while(n) {
        int lb = (n & 1);
        res |= lb;
        n = n >> 1;
        res = res << 1;
    }
    res = res >> 1;
    return res;
}

int main() {
    int n;
    cin >> n;
    int count = 0;
    int len = 0;
    while(count < n) {
        len++;
        count += (1 << ((len-1)/2));
    }
    count = count - (1 << ((len-1)/2));
    int offset = n - count -1;
    
    int ans = (1 << (len-1));
    ans |= (offset << (len/2));
    int valToRev = (ans >> ((len+1)/2));
    int rev = getRev(valToRev);
    
    ans |= rev;
    cout << ans << endl;
    return 0;
}