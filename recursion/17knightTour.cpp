#include<bits/stdc++.h>
using namespace std;

const int N = 100;

bool validKnightPos(int chess[][N], int n, int row, int col) {
    if(row >= n || row < 0) return false;
    if(col >=n || col < 0) return false;
    if(chess[row][col] > 0) return false;
    return true;
}

void displayChess(int chess[][N], int n) {
    for(int i = 0 ; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cout << chess[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

void printKnightTour(int chess[][N], int n, int row, int col, int move) {
    
    if(!validKnightPos(chess, n, row, col)) {//backtrack 
        return;
    }

    if(move == (n)*(n)) {
        chess[row][col] = move;
        displayChess(chess, n);
        chess[row][col] = 0;
        return;
    }

    
    
    chess[row][col] = move;
    printKnightTour(chess, n, row-1, col-2, move + 1);
    printKnightTour(chess, n, row-1, col+2, move + 1);
    printKnightTour(chess, n, row-2, col-1, move + 1);
    printKnightTour(chess, n, row-2, col+1, move + 1);
    printKnightTour(chess, n, row+1, col-2, move + 1);
    printKnightTour(chess, n, row+1, col+2, move + 1);
    printKnightTour(chess, n, row+2, col-1, move + 1);
    printKnightTour(chess, n, row+2, col+1, move + 1);
    chess[row][col] = 0;

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
    int x,y;
    cin >> x >> y;
    printKnightTour(chess, n, x, y, 1);
    return 0;
}