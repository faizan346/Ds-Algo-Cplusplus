#include<bits/stdc++.h>
using namespace std;

void print(vector<int>& dp, vector<int>& a, int n, int len, int last, string psf) {
    if(len == 0) {
        cout << psf << endl;
        return;
    }
    if(n <= 0) return;
    for(int i = n-1; i >= 0; i--) {
        if(dp[i] == len && a[i] < last) {
            print(dp, a, i, len-1,a[i], to_string(a[i]) + " -> " + psf);
        }
    }
}

void printAllLIS(vector<int>& a, int n) {
    vector<int> dp(n, 0);
    dp[0] = 1;
    int len = 1;
    for(int i = 1; i < n; i++) {
        dp[i] = 1;
        for(int j = 0; j < i; j++) {
            if(a[i] > a[j]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        len = max(len, dp[i]);
    }
    cout << len << endl;
    vector<int> v;
    for(int i = 0 ; i < n; i++) {
        if(dp[i] == len) {
            print(dp, a, i, len-1, a[i], to_string(a[i]));
        }
    }
}

int main() {
    int n;
    cin >> n;
    vector<int> a(n, 0);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    printAllLIS(a, n);
    return 0;
}