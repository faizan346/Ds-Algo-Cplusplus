#include<bits/stdc++.h>
using namespace std;

void solveSudoku(vector<vector<int>>& sud, vector<int>& rb, vector<int>& cb
        , vector<vector<int>>& gb, int i , int j) {
    
    if(i == 9) {
        for(auto y : sud) {
            for(auto x : y) cout << x << " ";
            cout << endl;
        }
        return;
    }
    
    if(sud[i][j] > 0) {
        solveSudoku(sud, rb, cb, gb, (j == 8) ? i+1 : i, (j == 8) ? 0 : j+1);
    } else {
        for(int num = 1; num <= 9; num++) {
            if((rb[i] & (1 << num)) == 0 && (cb[j] & (1 << num)) == 0 
                && (gb[i/3][j/3] & (1 << num)) == 0) {
                        
                sud[i][j] = num;
                rb[i] ^= (1 << num);    
                cb[j] ^= (1 << num);
                gb[i/3][j/3] ^= (1 << num);
                
                solveSudoku(sud, rb, cb, gb, (j == 8) ? i+1 : i, (j == 8) ? 0 : j+1);
                
                rb[i] ^= (1 << num);
                cb[j] ^= (1 << num);
                gb[i/3][j/3] ^= (1 << num);
                sud[i][j] = 0;
            }
        }
    }
    
}

int main() {
    vector<vector<int>> sudoku(9, vector<int>(9, 0));
    vector<int> rb(9, 0); // rows of bits; unset
    vector<int> cb(9, 0); // coloms of bits; unset 
    vector<vector<int>> gb(3, vector<int>(3,0)); // grids bits; unset
    for(int i = 0; i < 9; i++) {
        for(int j = 0; j < 9; j++) {
            cin >> sudoku[i][j];
            int digit = sudoku[i][j];
            //set the bits
            rb[i] |= (1 << digit);
            cb[j] |= (1 << digit);
            gb[i/3][j/3] |= (1 << digit);
        }
    }
    solveSudoku(sudoku, rb, cb, gb, 0, 0);
    return 0;
}