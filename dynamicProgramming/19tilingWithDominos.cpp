#include<bits/stdc++.h>
using namespace std;
// tiles dimenstion h*w = 2*1
//floor dimenstion h*w = 2*vol
int tiling(int vol, vector<int>& t) {
    if(vol == 0) return 1;
    if(vol < 0) return 0;
    if(t[vol] != -1) return t[vol];
    //one way just put straight tiles at the cost of 1 vol
    //other way is two put two tiles horizontally at cost of 2 vol.
    return t[vol] = tiling(vol - 1, t) + tiling(vol - 2, t);
}

int tiling(int vol) {
    int dp[vol+1];
    dp[0] = 1; // if no vol than only 1 way i.e empty tile
    dp[1] = 1; // if 1 vol 1 way that is 1 tile;
    for(int i = 2; i < vol+1; i++) {
        dp[i] = dp[i-1] + dp[i-2];
    }
    return dp[vol];
}

int main() {
    int vol;
    cin >> vol;
    cout <<tiling(vol) << endl;
    vector<int> t(vol+1, -1);
    cout << tiling(vol, t) << endl;
    return 0;
}