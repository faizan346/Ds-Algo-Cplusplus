#include<bits/stdc++.h>
using namespace std;

const int N = 100;

void printNqueen(int chess[][N], int n, string print, int row, int *col, int *rdig, int *ndig) {
    if(row == n) {
        cout << print << endl;
        return;
    }

    for(int i = 0; i < n; i++) {
        if(col[i] != 1 && rdig[row+i] != 1 && ndig[row-i + n-1] != 1) {
            chess[row][i] = 1;
            col[i] = 1;
            rdig[row+i] = 1;
            ndig[row-i +n-1] = 1;
            printNqueen(chess, n, print + (char)(row + '0') + '-' + (char)(i + '0') +", ", row+1, col, rdig, ndig);
            chess[row][i] = 0;
            col[i] = 0;
            rdig[row+i] = 0;
            ndig[row-i +n-1] = 0;
        }//if no condition satisfy backtrack from here.
    }
}

int main() {
    int n;
    cin >> n;
    int chess[n][N];
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            chess[i][j] = 0;
        }
    }
    int col[n] = {0};
    int rdig[2*n-1] = {0};
    int ndig[2*n-1] = {0};
    printNqueen(chess, n, "", 0, col, rdig, ndig);
    return 0;
}