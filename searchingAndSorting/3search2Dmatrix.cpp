#include<bits/stdc++.h>
using namespace std;

bool search(vector<vector<int>> &mat, int n, int m, int k) {
    int l = 0, r = n-1;
    while(l <= r) {
        int mid = (l+r)/2;
        if(mat[mid][0] == k) {
            return true;
        } else if(mat[mid][0] > k) {
            r = mid-1;
        } else {
            l = mid+1;
        }
    }
    int row = r;
    if(row < 0) return false;
    l = 0, r = m-1;
    while(l <= r) {
        int mid = (l+r)/2;
        if(mat[row][mid] == k) {
            return true;
        } else if(mat[row][mid] > k) {
            r = mid-1;
        } else {
            l = mid+1;
        }
    }
    return false;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> mat(n, vector<int>(m, 0));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> mat[i][j];
        }
    }
    int k;
    cin >> k;
    cout << (search(mat, n, m, k) ? "true" : "false") << endl;
    return 0;
}