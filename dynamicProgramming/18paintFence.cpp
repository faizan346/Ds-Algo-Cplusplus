#include<bits/stdc++.h>
using namespace std;

int paintFence(int n, int k, int lastTwo, int lastColor, vector<vector<vector<int>>>& t) {
    if(n == 0) {
        return 1;
    }
    if(t[n][lastColor+1][lastTwo] != -1) return t[n][lastColor+1][lastTwo];
    int ways = 0;
    if(lastTwo == 0) { //diff color
        for(int i = 0; i < k; i++) {
            if(lastColor == i) {
                ways += paintFence(n-1, k, 1, i, t);
            } else {
                ways += paintFence(n-1, k, 0, i, t);
            }
        }
    } else { // same color
        for(int i = 0; i < k; i++) {
            if(i != lastColor) {
                ways += paintFence(n-1, k, 0, i, t);
            }
        }
    }
    return t[n][lastColor+1][lastTwo] = ways;
}

//paint fence such that no 3 consequitive fence have same color.
// color can be of k types
int paintFence(int n, int k) {
    int same = k * 1; // ways to get same eg k = 3 , rrr, bbb, ggg
    int diff = k * (k - 1); // total ways minus same ways
    int total = same + diff;
    for(int i = 2; i < n; i++) {
        int nsame, ndiff, ntotal;
        nsame = diff * 1; //as we can ij -> ijj
        ndiff = total*(k - 1); // as we can ii -> iij and ij -> iji and here last element can be any color except curr last color
        ntotal = nsame + ndiff;

        same = nsame;
        diff = ndiff;
        total = ntotal;
    }
    return total;
}


int main() {
    int n, k;
    cin >> n >> k;
    cout << paintFence(n, k) << endl;
    vector<vector<vector<int>>> t(n+1,vector<vector<int>>(k+1, vector<int>(2, -1)));
    cout << paintFence(n, k, 0, -1, t) << endl;
    return 0;
}
