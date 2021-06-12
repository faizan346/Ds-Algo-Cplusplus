#include<bits/stdc++.h>
using namespace std;

class Pair {
    public:
    int i;
    int j;
    vector<int> psf;
    Pair(int i, int j, vector<int> psf) {
        this->i = i, this->j = j, this->psf = psf;
    }
};

void targetSum(vector<int>& a, int n, int tar) {
    vector<vector<bool>> dp(n+1, vector<bool>(tar+1, false));
    for(int i = 0; i < n+1; i++) {
        for(int j = 0; j < tar+1; j++) {
            if(j == 0) {
                dp[i][j] = true;
            } else if(i == 0) {
                dp[i][j] = false;
            } else {
                dp[i][j] = dp[i-1][j] || ((j-a[i-1] >= 0) ? dp[i-1][j-a[i-1]] : false);
            }
        }
    }
    // for(auto y : dp) {
    //     for(auto x : y) cout << ((x) ? "T":"F") << " ";
    //     cout << endl;
    // }
    cout << ((dp[n][tar]) ? "true" : "false") << endl;
    // i, j, psf
    queue<Pair> q;
    q.push(Pair(n, tar, vector<int>()));
    while(!q.empty()) {
        Pair p = q.front();
        q.pop();
        int i = p.i;
        int j = p.j;
        vector<int>& psf = p.psf;
        if(j == 0) { // total tar sum needed 0 then we can print the ans
            for(int i = psf.size()-1; i >= 0; i--) {
                cout << psf[i] << " ";
            }
            cout << endl;
        } else {
            if((j-a[i-1]) >= 0 && dp[i-1][j-a[i-1]] == true) {
                vector<int> psf1 = psf;
                psf1.push_back(i-1);
                q.push(Pair(i-1, j-a[i-1], psf1));
            }
            if(dp[i-1][j] == true) {
                q.push(Pair(i-1, j, psf));
            }
        }
    }
}

int main() {
    int n;
    cin >> n;
    vector<int> a(n, 0);
    for(int i = 0; i< n; i++) {
        cin >> a[i];
    }
    int tar;
    cin >> tar;
    targetSum(a, n, tar);
    return 0;
}