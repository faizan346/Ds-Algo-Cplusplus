#include<bits/stdc++.h>
using namespace std;

const int N = 100;

bool validQueenPosition(int chess[][N], int n, int row, int col) {
    for(int i = row-1; i >= 0; i--) {
        if(chess[i][col] == 1) return false;
    }

    for(int i = row-1, j = col-1; i >= 0 && j >= 0; i--, j--) {
        if(chess[i][j] == 1) return false;
    }

    for(int i = row-1, j = col+1; i >= 0 && j < n; i--, j++) {
        if(chess[i][j] == 1) return false;
    }

    return true;
}

void printNqueen(int chess[][N], int n, string print, int row) {
    if(row == n) {
        cout << print << endl;
        return;
    }

    for(int i = 0; i < n; i++) {
        if(validQueenPosition(chess, n, row, i)) {
            chess[row][i] = 1;
            printNqueen(chess, n, print + (char)(row + '0') + '-' + (char)(i + '0') +", ", row+1);
            chess[row][i] = 0;
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
    printNqueen(chess, n, "", 0);
    return 0;
}