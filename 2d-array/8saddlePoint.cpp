#include<bits/stdc++.h>
using namespace std;
// 4
// 11 12 13 14
// 21 22 23 24
// 31 32 33 34
// 41 42 43 44

// 41

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
    for(int i = 0; i < n; i++) {
        int minIdx = 0;
        for(int j = 1; j < m; j++){
            if(a[i][minIdx] > a[i][j]) {
                minIdx = j;
            }
        }
        int pots = a[i][minIdx];
        bool saddlePoint = true;
        for(int ii = 0; ii < n; ii++) {
            if(pots < a[ii][minIdx]) {
                saddlePoint = false;
            }
        }
        if(saddlePoint) {
            cout << pots << endl;
            break;
        }
    }
    return 0;
}