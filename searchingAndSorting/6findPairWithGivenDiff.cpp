#include<bits/stdc++.h>
using namespace std;

void solve(vector<int> &a, int n, int tar) {
    sort(a.begin(), a.end());
    int i = 0, j = 1;
    while(i < j && j < n) {
        int diff = a[j] - a[i];
        if(diff == tar) {
            cout << a[i] << " " << a[j] << endl;
            return;
        } else if(diff < tar) {
            j++;
        } else {
            i++;
        }
    }
    cout << "-1" << endl;
}

int main() {
    int n;
    cin >> n;
    vector<int> a(n, 0);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int tar;
    cin >> tar;
    solve(a, n, tar);
    return 0;
}