#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    int m = n;
    int a[n][m];
    for(int i = 0; i < n; i++) { 
        for(int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }
    int r[n][m];
    //transpose;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            r[j][i] = a[i][j];
        }
    }
    //swap;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m/2; j++) {
            swap(r[i][j], r[i][m-1-j]);
        }
    }
    //display
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cout << r[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}