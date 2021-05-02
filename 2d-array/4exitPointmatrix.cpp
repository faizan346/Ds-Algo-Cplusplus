#include<bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    int a[n][m];
    for(int i = 0; i < n; i++) { 
        for(int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }
    int dir = 0;
    int i = 0, j = 0;
    while(true) {
        if(a[i][j] == 1) {
            dir = (dir + 1) % 4;
        }
        if(dir == 0) {
            j++;
        } else if(dir == 1) {
            i++;
        } else if(dir == 2) {
            j--;
        } else if(dir == 3) {
            i--;
        }
        if(i < 0 || j < 0 || i == n || j == m) {
            break;
        }
    }
    if(i < 0) {
        i++;
    } else if(i == n) {
        i--;
    } else if(j < 0) {
        j++;
    } else if(j == m) {
        j--;
    }
    cout << i << " " << j << endl;
    return 0;
}