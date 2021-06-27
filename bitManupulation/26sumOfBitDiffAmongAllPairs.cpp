#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n, 0);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    long long ans = 0;
    for(int i = 31; i >= 0; i--) {
        long long ones = 0;
        long long zeros = 0;
        for(auto x : a) {
            if((x & (1 << i)) == 0) {
                zeros++;
            } else {
                ones++;
            }
        }
        ans += 2 * (ones * zeros);
    }
    cout << ans << endl;
    return 0;
}