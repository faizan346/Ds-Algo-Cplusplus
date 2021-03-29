#include<bits/stdc++.h>
using namespace std;

void display(int board[][9]) {
    for(int i= 0; i < 9; i++) {
        for(int j = 0; j < 9; j++) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}

bool validNumber(int board[][9], int row, int col, int num) {
    for(int i = 0; i < 9; i++) {
        if(board[row][i] == num) return false;
    }
    for(int i = 0; i < 9; i++) {
        if(board[i][col] == num) return false;
    }

    //to find submatrix starting index .....
    int subi = row / 3 * 3;
    int subj = col / 3 * 3;
    for(int i = 0; i < 3; i ++) {
        for(int j = 0; j < 3; j++) {
            if(board[subi+i][subj+j] == num) return false;
        }
    }
    return true;    
}

void solveSudoku(int board[][9], int row, int col) {
    if(row == 9) {
        display(board);
        return;
    }

    if(col == 9) {
        row = row + 1;
        col = 0;
    }

    if(board[row][col] != 0) {
        solveSudoku(board, row, col+1);
    } else {
        for(int i = 1; i <= 9; i++) {//options for next level
            if(validNumber(board, row, col, i)) {
                board[row][col] = i;
                solveSudoku(board, row, col+1); //lead to next level
                board[row][col] = 0;
            }
        }
    }
}

int main() {
    int board[9][9] = { {3, 0, 6, 5, 0, 8, 4, 0, 0}, 
                        {5, 2, 0, 0, 0, 0, 0, 0, 0}, 
                        {0, 8, 7, 0, 0, 0, 0, 3, 1}, 
                        {0, 0, 3, 0, 1, 0, 0, 8, 0}, 
                        {9, 0, 0, 8, 6, 3, 0, 0, 5}, 
                        {0, 5, 0, 0, 9, 0, 6, 0, 0}, 
                        {1, 3, 0, 0, 0, 0, 2, 5, 0}, 
                        {0, 0, 0, 0, 0, 0, 0, 7, 4}, 
                        {0, 0, 5, 2, 0, 6, 3, 0, 0} };
    // for(int i = 0; i < 9; i++) {
    //     for(int j = 0; j < 9; j++) {
    //         cin >> board[i][j];
    //     }
    // }
    solveSudoku(board, 0, 0);
    return 0;
}