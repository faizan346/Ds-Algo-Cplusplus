#include<bits/stdc++.h>
using namespace std;

int const M = 100;

void iterateComponent(int a[][M], int n, int m, int i, int j, int visited[][M]) {
    if(i < 0 || j < 0 || i == n || j == m || a[i][j] == 1 || visited[i][j] == 1) {
        return;
    }
    visited[i][j] = 1;
    iterateComponent(a, n, m, i-1, j, visited);
    iterateComponent(a, n, m, i, j-1, visited);
    iterateComponent(a, n, m, i+1, j, visited);
    iterateComponent(a, n, m, i, j+1, visited);
}
// 4 4
// 0 0 1 1
// 1 1 0 0
// 1 1 1 1
// 0 0 0 0 
int main() {
    int m ,n;
    cin >> n >> m;
    int a[n][M];

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }

    int visited[n][M];
    for(int i=0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            visited[i][j] = 0;
        }
    }
    int count = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(a[i][j] == 0 && !visited[i][j]) {
                iterateComponent(a, n, m, i, j, visited);
                count++;
            }
        }
    }
    cout << count << endl;
    return 0;
}