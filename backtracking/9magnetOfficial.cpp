#include<bits/stdc++.h>
using namespace std;

bool valid(vector<int> &t, vector<int> &l, vector<int> &r, vector<int> &b) {
    for(auto x : t) {
        if(x != 0 && x > -2) return false;
    }
    for(auto x : l) {
        if(x != 0 && x > -2) return false;
    }
    for(auto x : r) {
        if(x != 0 && x > -2) return false;
    }
    for(auto x : b) {
        if(x != 0 && x > -2) return false;
    }
    return true;
}

void solve(int i, int j, vector<vector<char>>& mat, vector<int> &t, vector<int> &l
            ,vector<int> &r, vector<int> &b, vector<vector<char>>& ans) {
    
    int m = mat[0].size()-1; // last index of column
    if(i == mat.size()) {
        if(!valid(t,l,r,b)) return;
        for(auto y : ans) {
            for(auto x : y) cout << x << " ";
            cout << endl;
        }
        cout << endl;
        return;
    }
    if(mat[i][j] == 'L' || mat[i][j] == 'T') {
        ans[i][j] = '-';
        r[i]--, b[j]--;
        if(r[i] != -1 && b[j] != -1)
            solve((j == m) ? i+1 : i, (j == m) ? 0 : j+1, mat, t, l, r, b, ans);
        r[i]++, b[j]++;
        ans[i][j] = '+';
        t[j]--, l[i]--;
        if(t[j] != -1 && l[i] != -1)
            solve((j == m) ? i+1 : i, (j == m) ? 0 : j+1, mat, t, l, r, b, ans);
        t[j]++, l[i]++;
        ans[i][j] = 'X';
        solve((j == m) ? i+1 : i, (j == m) ? 0 : j+1, mat, t, l, r, b, ans);
    } else {
        if(mat[i][j] == 'R') {
            if(ans[i][j-1] == 'X') ans[i][j] = 'X';
            else ans[i][j-1] == '-' ? ans[i][j] = '+' : ans[i][j] = '-';
        } else {
            if(ans[i-1][j] == 'X') ans[i][j] = 'X';
            else ans[i-1][j] == '-' ? ans[i][j] = '+' : ans[i][j] = '-';
        }
        if(ans[i][j] == '-') {
            r[i]--, b[j]--;
        } else if(ans[i][j] == '+'){
            t[j]--, l[i]--;
        }
        if(t[j] != -1 && l[i] != -1 && r[i] != -1 && b[j] != -1)
            solve((j == m) ? i+1 : i, (j == m) ? 0 : j+1, mat, t, l, r, b, ans);
        if(ans[i][j] == '-') {
            r[i]++, b[j]++;
        } else if(ans[i][j] == '+'){
            t[j]++, l[i]++;
        }
        ans[i][j] = 'X';
    }      
}


int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<char>> mat(n, vector<char>(m, ' '));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> mat[i][j];
        }
    }
    vector<int> top(m, 0);
    for(int i = 0; i < m; i++) {
        cin >> top[i];
        if(top[i] == -1) top[i] = -2;
    }
    vector<int> left(n, 0);
    for(int i = 0; i < n; i++) {
        cin >> left[i];
        if(left[i] == -1) left[i] = -2;
    }
    vector<int> right(n, 0);
    for(int i = 0; i < n; i++) {
        cin >> right[i];
        if(right[i] == -1) right[i] = -2;
    }
    vector<int> bottom(m, 0);
    for(int i = 0; i < m; i++) {
        cin >> bottom[i];
        if(bottom[i] == -1) bottom[i] = -2;
    }
    vector<vector<char>> ans(n, vector<char>(m, 'X'));
    solve(0, 0, mat, top, left, right, bottom, ans);
    
    return 0;
}