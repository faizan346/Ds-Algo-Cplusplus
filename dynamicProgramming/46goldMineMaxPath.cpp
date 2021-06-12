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

void maxGold(vector<vector<int>>& mine, int n, int m) {
    vector<vector<int>> dp(n, vector<int>(m, 0));
    for(int j = m-1; j >= 0; j--) {
        for(int i = 0; i < n; i++) {
            if(j == m-1) {
                dp[i][j] = mine[i][j];
            } else if(i == 0){
                dp[i][j] = mine[i][j] + max(dp[i][j+1], dp[i+1][j+1]);
            } else if(i == n-1) {
                dp[i][j] = mine[i][j] + max(dp[i][j+1], dp[i-1][j+1]);
            } else {
                dp[i][j] = mine[i][j] + max(dp[i-1][j+1],max(dp[i][j+1], dp[i+1][j+1]));
            }
        } 
    }
    int maxi = 0;
    for(int i = 0; i < n; i++) {
        if(dp[i][0] > dp[maxi][0]) {
            maxi = i;
        }
    }
    int maxVal = dp[maxi][0];
    cout << maxVal << endl; 
    for(int i = 0; i < n; i++) {
        if(dp[i][0] == maxVal) {
            queue<Pair> q;
            q.push(Pair(i, 0, to_string(i)));
            while(!q.empty()) {
                Pair p = q.front();
                q.pop();
                int i = p.i;
                int j = p.j;
                string psf = p.psf;
                if(j == m-1) {
                    cout << psf << endl;
                    continue;
                }
                if(i == 0) {
                    int d2 = dp[i][j+1];
                    int d3 = dp[i+1][j+1];
                    int h = max(d2, d3);
                    if(d2 == h) {
                        q.push(Pair(i, j+1, psf+" d2"));
                    }
                    if(d3 == h) {
                        q.push(Pair(i+1, j+1, psf+" d3"));
                    }
                } else if(i == n-1) {
                    int d1 = dp[i-1][j+1];
                    int d2 = dp[i][j+1];
                    int h = max(d1, d2);
                    if(d1 == h) {
                        q.push(Pair(i-1, j+1, psf+" d1"));
                    }
                    if(d2 == h) {
                        q.push(Pair(i, j+1, psf+" d2"));
                    }
                } else {
                    int d1 = dp[i-1][j+1];
                    int d2 = dp[i][j+1];
                    int d3 = dp[i+1][j+1];
                    int h = max(d1, max(d2, d3));
                    if(d1 == h) {
                        q.push(Pair(i-1, j+1, psf+" d1"));
                    }
                    if(d2 == h) {
                        q.push(Pair(i, j+1, psf+" d2"));
                    }
                    if(d3 == h) {
                        q.push(Pair(i+1, j+1, psf+" d3"));
                    }
                }
            }
        }
    }
    
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> mine(n, vector<int>(m, 0));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> mine[i][j];
        }
    }
    maxGold(mine, n, m);
    return 0;
}