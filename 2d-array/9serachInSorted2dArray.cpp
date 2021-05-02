#include<bits/stdc++.h>
using namespace std;
// 4
// 11 12 13 14
// 21 22 23 24
// 31 32 33 34
// 41 42 43 44



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
    int k;
    cin >> k;
    int i = 0;
    int j = m-1 ;
    while(i < n && j >= 0) {
        if(a[i][j] == k) {
            cout << "found at : " << i << " " << j<< endl;
            break;
        } else if(a[i][j] < k) {
            i++;
        } else if(a[i][j] > k) {
            j--;
        }
    }
    if(i == n || j < 0) {
        cout << "no such element " << endl;
    }
    return 0;
}