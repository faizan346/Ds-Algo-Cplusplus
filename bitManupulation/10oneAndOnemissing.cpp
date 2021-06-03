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
    int sum = 0;
    for(int i = 0; i < n; i++) {
        num = num^v[i]^(i+1);
        sum += v[i];
    }
    int asum = n*(n+1) / 2;
    int rsb = num & -num;
    int a = 0, b = 0;
    for(int i = 0; i < n; i++) {
        if((v[i] & rsb) == 0) {
            a = a^v[i];
        } else {
            b = b^v[i];
        }
        if(((i+1) & rsb) == 0) {
            a = a^(i+1);
        } else {
            b = b^(i+1);
        }
    }
    if(asum > sum) {
        cout << "Missing Number -> " << max(a,b) << endl;
        cout << "Repeating Number -> " << min(a,b) << endl;
    } else {
        cout << "Missing Number -> " << min(a,b) << endl;
        cout << "Repeating Number -> " << max(a,b) << endl;
    }
    return 0;
}