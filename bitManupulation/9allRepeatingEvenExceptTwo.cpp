#include<bits/stdc++.h>
using namespace std;


int main() {    
    int n;
    cin >> n;
    vector<int> v(n, 0);
    for(int i = 0; i < n; i++) {
        cin >> v[i];
    }
    // we found num = a^b
    int num = 0;
    for(int i = 0; i < n; i++) {
        num = num^v[i];
    }
    // now find rsb of num, as we know we got rsb becoz a and b bit won't
    // cancel out. it can help us to divide them in two groups
    // one contain a and other contain b.
    int rsb = num & -num;
    int a = 0, b = 0;
    for(int i = 0; i < n; i++) {
        if((v[i] & rsb) == 0) {
            a = a^v[i];
        } else {
            b = b^v[i];
        }
    }
    cout << min(a,b) << endl;
    cout << max(a,b) << endl;
    return 0;
}