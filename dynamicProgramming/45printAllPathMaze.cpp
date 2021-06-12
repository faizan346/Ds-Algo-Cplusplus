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

void minimumCost(vector<vector<int>>& maze, int n, int m) {
    vector<vector<int>> dp(n, vector<int>(m, 0));
    for(int i = n-1; i >= 0; i--) {
        for(int j = m-1; j >= 0; j--) {
            if(i == n-1 && j == m-1) {
                dp[i][j] = maze[i][j];
            } else if(i == n-1) {
                dp[i][j] = dp[i][j+1] + maze[i][j];
            } else if(j == m-1) {
                dp[i][j] = dp[i+1][j] + maze[i][j];
            } else {
                dp[i][j] = min(dp[i+1][j], dp[i][j+1]) + maze[i][j];
            }
        }
    }
    cout << dp[0][0] << endl;
    //i, j, psf
    queue<Pair> q;
    q.push(Pair{0, 0, ""});
    while(!q.empty()) {
        Pair p = q.front();
        q.pop();
        if(p.i == n-1 && p.j == m-1) cout << p.psf << endl;
        else if(p.i == n-1) {
            q.push(Pair{p.i, p.j + 1, p.psf + "H"});
        } else if(p.j == m-1) {
            q.push(Pair{p.i + 1, p.j, p.psf + "V"});
        } else {
            if(dp[p.i+1][p.j] > dp[p.i][p.j+1]) {
                q.push(Pair{p.i, p.j + 1, p.psf + "H"});
            } else if(dp[p.i+1][p.j] < dp[p.i][p.j+1]) {
                q.push(Pair{p.i + 1, p.j, p.psf + "V"});
            } else {
                q.push(Pair{p.i + 1, p.j, p.psf + "V"});
                q.push(Pair{p.i, p.j + 1, p.psf + "H"});
            }
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> maze(n, vector<int>(m, 0));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> maze[i][j];
        }
    }
    minimumCost(maze, n, m);
    return 0;
}