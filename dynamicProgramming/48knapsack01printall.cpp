#include<bits/stdc++.h>
using namespace std;

class Pair {
    public:
    int i;
    int j;
    string psf;
    Pair(int i, int j, string psf) {
        this->i = i, this->j = j, this->psf = psf;
    }
};

void knapsack(vector<int> costs, vector<int> wts, int n, int cap) {
    vector<vector<int>> dp(n+1, vector<int>(cap+1, 0));
    for(int i = 0; i < n+1; i++) {
        for(int j = 0; j < cap+1; j++) {
            if(i == 0) { // if no element
                dp[i][j] = 0;
            } else if(j == 0) { // if no cap
                dp[i][j] = 0;
            } else {
                int inc = (j >= wts[i-1]) ? dp[i-1][j-wts[i-1]] + costs[i-1]: 0;
                int exc = dp[i-1][j];
                dp[i][j] = max(inc, exc);
            }
        }
    }
    cout << dp[n][cap] << endl;
    for(auto y : dp) {
        for(auto x : y) cout << x << " ";
        cout << endl;
    }
    if(dp[n][cap] == 0) return;
    // i, j , psf;
    queue<Pair> q;
    q.push(Pair(n, cap, ""));
    while(!q.empty()) {
        Pair p = q.front();
        q.pop();
        int i = p.i;
        int j = p.j;
        string psf = p.psf;
        if(j == 0 || i == 0) cout << psf << endl;
        else {
            int h = dp[i][j];
            if(j >= wts[i-1] && h == dp[i-1][j-wts[i-1]] + costs[i-1]) {
                q.push(Pair(i-1, j-wts[i-1], to_string(i-1) + " " + psf));
            }
            if(h == dp[i-1][j]) {
                q.push(Pair(i-1, j, psf));
            }
        }
    }
}

int main() {
    int n;
    cin >> n;
    vector<int> costs(n, 0);
    vector<int> wts(n, 0);
    for(int i = 0; i < n; i++) {
        cin >> costs[i];
    }
    for(int i = 0; i < n; i++) {
        cin >> wts[i];
    }
    int cap;
    cin >> cap;
    knapsack(costs, wts, n, cap);
}