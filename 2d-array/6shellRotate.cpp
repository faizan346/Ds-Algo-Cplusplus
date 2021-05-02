#include<bits/stdc++.h>
using namespace std;

const int M = 100;

void reverse(int *a, int i, int j) {
    while(i < j) {
        swap(a[i], a[j]);
        i++;
        j--;
    }
}
void rotate(int *a, int n, int k) {
    k = k%n;
    if(k < 0) k = k + n;
    k = n - k;
    reverse(a, 0, k-1);
    reverse(a, k, n-1);
    reverse(a, 0, n-1);
}

void display(int a[][M], int n, int m) {
    for(int i = 0 ; i< n; i ++) {
        for(int j = 0; j < m; j++) {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
}
void shellRotate(int a[][M], int n, int m, int shell, int rot) {
    int rmin = shell - 1, rmax = n - shell;
    int cmin = shell - 1, cmax = m - shell;
    int tne = 2 * (rmax - rmin + cmax - cmin);
    int b[tne];
    int k = 0;
    //fill b from shell
    //left wall
    for(int i = rmin; i <= rmax; i++) {
        b[k] = a[i][cmin] ;
        k++;
    }
    //bottom wall
    for(int i = cmin + 1; i <= cmax; i++) {
        b[k] = a[rmax][i] ;
        k++;
    }
    //right wall
    for(int i = rmax - 1; i >= rmin; i--) {
        b[k] = a[i][cmax] ;
        k++;
    }
    //top wall
    for(int i = cmax - 1; i > cmin; i--) {
        b[k] = a[rmin][i] ;
        k++;
    }
    //rotate b
    rotate(b, tne, rot);
    //fill b back to shell
    //left wall
    k = 0;
    for(int i = rmin; i <= rmax; i++) {
        a[i][cmin] = b[k];
        k++;
    }
    //bottom wall
    for(int i = cmin + 1; i <= cmax; i++) {
        a[rmax][i] = b[k];
        k++;
    }
    //right wall
    for(int i = rmax - 1; i >= rmin; i--) {
        a[i][cmax] = b[k];
        k++;
    }
    //top wall
    for(int i = cmax - 1; i > cmin; i--) {
        a[rmin][i] = b[k];
        k++;
    }
}

int main() {
    int n;
    cin >> n;
    int m = n;
    int a[n][M];
    for(int i = 0; i < n; i++) { 
        for(int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }
    int shell, k;
    cin >> shell >> k;
    if(!(shell <= n/2 && shell <= m/2)) {
        cout << "not a valid shell" << endl;
        return 0;
    }
    shellRotate(a, n, m, shell, k);
    display(a, n, m);
   
    return 0;
}