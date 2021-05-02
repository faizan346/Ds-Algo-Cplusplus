#include<bits/stdc++.h>
using namespace std;



int main() {
    int n, m;
    cin >> n >> m;
    int a[n][m];
    for(int i = 0; i < n; i++){ 
        for(int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }
    int n2, m2;
    cin >> n2 >> m2;
    int b[n2][m2];
    for(int i = 0; i < n2; i++){ 
        for(int j = 0; j < m2; j++) {
            cin >> b[i][j];
        }
    }
    if(m != n2) {
        cout << "not possible" << endl;
        return 0;
    }
    int c[n][m2];
    for(int i = 0; i < n; i ++) {
        for(int j = 0; j < m2; j++) {
            c[i][j] = 0;
            for(int k = 0; k < m; k++) {
                c[i][j] += a[i][k] * b[k][j];
            }
        }
    }
    for(int i = 0; i < n; i ++) {
        for(int j = 0; j < m2; j++) {
            cout << c[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}