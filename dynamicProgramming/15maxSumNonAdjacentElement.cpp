#include<bits/stdc++.h>
using namespace std;

int maxSumNAE(vector<int>& a, int n, int include, vector<vector<int>>& t) {
    if(n == 0) {
        return 0;
    }
    if(t[n][include] != -1) return t[n][include];
    if(include == 1) { //allow to include or exclude and take optimum sol
        return t[n][include] = max(maxSumNAE(a, n-1, 0, t) + a[n-1] //include kra
                                , maxSumNAE(a, n-1, 1, t)); // exclude kra
    } else { //include == 0 toh exclude kre
        return t[n][include] = maxSumNAE(a, n-1, 1, t);
    }
} 

int maxSumNAE(vector<int>& a) {
    int n = a.size();
    //inc means max of oinc and oexc
    //exc means oinc
    //so here inc exc is more like flag rather than real exclude include
    int oinc = 0; // when no element max sum will be 0 for both inc and exc;
    int oexc = 0;
    for(int i = 0; i < n; i++) {
        int exc = oinc; 
        int inc = max(oexc + a[i], oinc);
        oinc = inc;
        oexc = exc;
    }
    //answer would flag oinc after n iteration.
    return oinc;
}

int main() {
    int n;
    cin >> n;
    vector<int> a;
    for(int i = 0; i < n; i++) {
        int v;
        cin >> v;
        a.push_back(v);
    }
    cout << maxSumNAE(a) << endl;
    vector<vector<int>> t(n+1,vector<int>(2, -1));
    cout << maxSumNAE(a, n, 1, t) << endl;
    return 0;
}