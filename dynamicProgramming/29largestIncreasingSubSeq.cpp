#include<bits/stdc++.h>
using namespace std;

int largestIncSubSeq(vector<int>& a) {
    int n = a.size();
    int dp[n]; // tells the largestIncSubSeq upto ith block if the ith element part of it.
    dp[0] = 1;
    for(int i = 1; i < n; i++) {
        dp[i] = 1; // when it is not part of subSeq
        for(int j = 0; j < i; j++) {
            if(a[i] >= a[j]) { // if it can be part of IncSubSeq
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }
    int len = INT_MIN;
    for(auto x : dp) {
        if(len < x) len = x;
    }
    return len;
}
// 10
// 10 22 9 33 21 50 41 60 80 1
// 6
int main () {
    int n;
    cin >> n;
    vector<int> a;
    for(int i = 0; i < n; i++) {
        int v;
        cin >> v;
        a.push_back(v);
    }
    cout << largestIncSubSeq(a) << endl;
}