#include<bits/stdc++.h>
using namespace std;

bool search(vector<vector<int>> &a, int n, int m, int k) {
    int i = 0, j = m-1;
    while(i < n && j > 0) {
        if(a[i][j] == k) {
            return true;
        } else if(a[i][j] < k) {
            i++;
        } else {
            j--;
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