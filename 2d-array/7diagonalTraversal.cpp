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
    cout << endl;
    for(int j = 0; j < m; j++) {
        int jj = j;
        int i = 0;
        while(i < n && jj < m) {
            cout << a[i][jj] << " ";
            i++;
            jj++;
        } 
        cout << endl;
    }
    return 0;
}