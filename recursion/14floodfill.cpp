#include<bits/stdc++.h>
using namespace std;

const int M = 10000;

void floodFill(int maze[][M], int r, int c, int n, int m, int visit[][M], string print) {
    if(r < 0 || c < 0 || r == n || c == m || maze[r][c] == 1 || visit[r][c] == 1) {
        //backtracking conditions...
        return;
    }

    if(r == n-1 && c == m-1) {
        cout << print << endl;
    }

    visit[r][c] = 1;
    floodFill(maze, r-1, c, n , m, visit, print + 't');
    floodFill(maze, r, c-1, n , m, visit, print + 'l');
    floodFill(maze, r+1, c, n , m, visit, print + 'd');
    floodFill(maze, r, c+1, n , m, visit, print + 'r');
    visit[r][c] = 0;
}

int main() {
    int n,m;
    cin >> n >> m;
    int a[n][M];
    for(int i = 0; i < n; i ++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }
    int visit[n][M];
    for(int i = 0; i < n; i ++) {
        for (int j = 0; j < m; j++) {
            visit[i][j] = 0;
        }
    }
    floodFill(a,0,0,n,m,visit,"");
    return 0;
}