#include<bits/stdc++.h>
using namespace std;

class Pair {
    public:
    int ind;
    int jumps;
    string psf;
    Pair(int i, int j, string p) {
        ind = i;
        jumps = j;
        psf = p;
    }
};

void printPaths(vector<int>& a, int n) {
    vector<int> dp(n, 0); // min jumps from given index
    dp[n-1] = 0;
    for(int i = n-2; i >= 0; i--) {
        int jumps = a[i];
        int m = INT_MAX - 1;
        for(int j = 1; j <= jumps; j++) {
            int pos = i + j;
            if(pos >= n) break;
            m = min(m, dp[pos]);
        }
        dp[i] = m + 1;
    }
    cout << dp[0] << endl;
    queue<Pair> q;
    q.push(Pair(0, dp[0], "0"));
    while(!q.empty()) {
        Pair p = q.front();
        q.pop();
        if(p.ind == n-1) { // and p.jumps == 0
            cout << p.psf << " ." << endl;
        }
        for(int j = 1; j <= a[p.ind]; j++) {
            int jumpedInd = p.ind + j;
            if(jumpedInd >= n) break;
            if(dp[jumpedInd] == p.jumps - 1) {
                q.push(Pair(jumpedInd, dp[jumpedInd], p.psf + " -> " + to_string(jumpedInd)));
            }
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
    printPaths(a, n);
    return 0;
}