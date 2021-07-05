#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n+1, 0);
    int q;
    cin >> q;
    for(int i = 0; i < q; i++) {
        int l, m, k;
        cin >> l >> m >> k;
        a[l] += k;
        a[m+1] -= k;
    }
    cout << a[0] << " ";
    for(int i = 1; i < n; i++) {
        a[i] = a[i] + a[i-1];
        cout << a[i] << " ";
    }
    cout << endl;
    return 0;
}