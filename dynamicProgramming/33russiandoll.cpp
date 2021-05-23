#include<bits/stdc++.h>
using namespace std;

class Doll {
    public:
    int w;
    int h;
};

bool compare(Doll a, Doll b) {
    if(a.w == b.w) {
        return a.h < b.h;
    }
    return a.w < b.w;
}

int longestNonOverLapBridges(vector<Doll>& b) {
    sort(b.begin(), b.end(), compare);
    int dp[b.size()];
    dp[0] = 1;
    for(int i = 1; i < b.size(); i++) {
        dp[i] = 1;
        for(int j = 0; j < i; j++) {
            if(b[i].h >= b[j].h) {
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
    vector<Doll> dolls;
    for(int i = 0; i < n; i++) {
        Doll b;
        cin >> b.w >> b.h;
        dolls.push_back(b);
    }
    cout << longestNonOverLapBridges(dolls) << endl;
    return 0;
}