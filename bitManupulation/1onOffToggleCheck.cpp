#include<bits/stdc++.h>
using namespace std;


int main() {
    int n, i ,j ,k, m;
    cin >> n >> i >> j >> k >> m;
    int onMask = (1 << i);
    cout << (n | onMask) << endl;
    int offMask = ~(1 << j);
    cout << (n & offMask) << endl;
    int toggleMask = (1 << k);
    cout << (n ^ toggleMask) << endl;
    int checkMask = (1 << m);
    cout << ((n & checkMask) ? "true" : "false") << endl;
    return 0;
}