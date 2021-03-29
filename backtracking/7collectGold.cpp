#include<bits/stdc++.h>
using namespace std;

const int N = 100;

void travelAndCollectGold(int mine[][N],int n, int i, int j, int visited[][N], int &sum) {
    if(i < 0 || j < 0 || i == n || j == n || mine[i][j] == 0 || visited[i][j] == 1) {
        return;
    }
    visited[i][j] = 1;
    sum = sum + mine[i][j];
    travelAndCollectGold(mine, n, i-1, j, visited, sum);
    travelAndCollectGold(mine, n, i, j-1, visited, sum);
    travelAndCollectGold(mine, n, i+1, j, visited, sum);
    travelAndCollectGold(mine, n, i, j+1, visited, sum);
}

// 7
// 10 0 100 200 0 8 0
// 20 0 0 0 0 6 0
// 30 0 0 9 12 3 4
// 40 0 2 5 8 3 11
// 0 0 0 0 0 9 0
// 5 6 7 0 7 4 2
// 8 9 10 0 1 10 8
int main() {
    int n;
    cin >> n;
    int mine[n][N];
    for(int i = 0; i < n; i ++) {
        for(int j = 0; j < n; j++) {
            cin >> mine[i][j];
        }
    }
    int visited[n][N];
    for(int i = 0; i < n; i ++) {
        for(int j = 0; j < n; j++) {
            visited[i][j] = 0;
        }
    }
    int max = INT_MIN;
    for(int i = 0; i < n; i ++) {
        for(int j = 0; j < n; j++) {
            if(mine[i][j] != 0 && visited[i][j] == 0);
            int sum = 0;
            travelAndCollectGold(mine, n, i, j, visited, sum);
            if(sum > max) {
                max = sum;
            }
        }
    }
    cout << max << endl;
    return 0;
}