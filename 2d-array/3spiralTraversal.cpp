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
    int tne = n*m;
    int count = 0;
    int rmin = 0, rmax = n-1;
    int cmin = 0, cmax = m-1;
    while(count < tne) {
        //left wall
        for(int i = rmin; i <= rmax && count < tne; i++) {
            count++;
            cout << a[i][cmin] << " ";
        }
        cmin++;
        //bottom wall
        for(int j = cmin; j <= cmax && count < tne; j++) {
            count++;
            cout << a[rmax][j] << " ";
        }
        rmax--;
        //right wall
        for(int i = rmax; i >= rmin && count < tne; i--) {
            count++;
            cout << a[i][cmax] << " ";
        }
        cmax--;
        //top wall
        for(int j = cmax; j >= cmin && count < tne; j--) {
            count++;
            cout << a[rmin][j] << " ";
        }
        rmin++;
    }
    cout << endl;
    return 0;
}