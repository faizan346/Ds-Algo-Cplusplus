#include<bits/stdc++.h>
using namespace std;

void solveQueens(int &n, int i, string psf, int ldb, int rdb, int cb) {
    if(i == n) {
        cout << psf << "." << endl;
        return;
    }
    
    for(int j = 0; j < n; j++) {
        if((rdb & (1<<(j-i+n-1))) == 0 && (ldb & (1<<(j+i))) == 0 && (cb & (1<<j)) == 0) {
            
            solveQueens(n, i+1, psf+to_string(i)+"-"+to_string(j)+", "
                , ldb^(1<<(j+i)), rdb^(1<<(j-i+n-1)), cb^(1<<j));
        }
    }
}

int main() {
    int n;
    cin >> n;
    int ldb, rdb, cb; // left dig, right dig, col bits
    ldb = rdb = cb = 0; // unset all bits
    solveQueens(n, 0, "", ldb, rdb, cb);
    
    return 0;
}