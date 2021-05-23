#include<bits/stdc++.h>
using namespace std;

class Bridge {
    public:
    int left;
    int right;
};

bool compare(Bridge a, Bridge b) {
    if(a.left == b.left) {
        return a.right < b.right;
    }
    return a.left < b.left;
}

int longestNonOverLapBridges(vector<Bridge>& b) {
    sort(b.begin(), b.end(), compare);
    int dp[b.size()];
    dp[0] = 1;
    for(int i = 1; i < b.size(); i++) {
        dp[i] = 1;
        for(int j = 0; j < i; j++) {
            if(b[i].right >= b[j].right) {
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

int main() {
    int n;
    cin >> n;
    vector<Bridge> bridges;
    for(int i = 0; i < n; i++) {
        Bridge b;
        cin >> b.left >> b.right;
        bridges.push_back(b);
    }
    cout << longestNonOverLapBridges(bridges) << endl;
    return 0;
}