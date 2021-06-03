#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n, 0);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int ans = 0;
    for(int i = 0; i < n; i++) {
        int x = 0;
        for(int k = i; k < n; k++) {
            x = x ^ a[k];
            if(x == 0) {
                 ans += k-i;
            }
        }
    }
    cout << ans << endl;
    return 0;
}