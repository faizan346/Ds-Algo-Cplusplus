#include<bits/stdc++.h>
using namespace std;

int largestSumIncSubSeq(vector<int>& a) {
    int n = a.size();
    int dp[n]; // tells the largestSumIncSubSeq upto ith block.
    dp[0] = a[0];
    for(int i = 1; i < n; i++) {
        dp[i] = a[i]; // if not part of subSeq them sum would be the number itself
        for(int j = 0; j < i; j++) {
            if(a[i] >= a[j]) { // if it can be part of IncSubSeq
                dp[i] = max(dp[i], dp[j] + a[i]);
            }
        }
    }
    int largest = INT_MIN;
    for(auto x : dp) {
        if(largest < x) largest = x;
    }
    return largest;
}
// 12
// 100 200 10 22 9 33 21 50 41 60 80 1
// 300

int main () {
    int n;
    cin >> n;
    vector<int> a;
    for(int i = 0; i < n; i++) {
        int v;
        cin >> v;
        a.push_back(v);
    }
    cout << largestSumIncSubSeq(a) << endl;
}