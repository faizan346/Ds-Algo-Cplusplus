#include<bits/stdc++.h>
using namespace std;

int stockExchange(vector<int>& a, int n, int sc, int state, vector<vector<int>>& t) {
    if(n == 0 && state == 0) return 0;
    if(n == 0 && state == 1) return INT_MIN;
    if(t[n][state] != -1) return t[n][state];
    int profit = 0;
    if(state == 1) { // buy state
        profit = max(stockExchange(a, n-1, sc, 0, t) - a[n-1], stockExchange(a, n-1, sc, 1, t));
    } else { // sell state
        profit = max(stockExchange(a, n-1, sc, 1, t) + a[n-1] - sc, stockExchange(a, n-1, sc, 0, t));
    }
    return t[n][state] = profit;
}

int stockExchange(vector<int>& a, int sc) {
    int bs = -1*a[0]; // max profit when buyState
    int ss = 0; // max profit when soldState
    for(int i = 1; i < a.size(); i++) {
        int nbs, nss;
        nbs = max(bs, ss - a[i]);
        nss = max(ss, bs + a[i] - sc);

        bs = nbs;
        ss = nss;
    }
    return ss;
}

// 12
// 10 15 17 20 16 18 22 20 22 20 23 25
// 3
// 13

int main() {
    int n;
    cin >> n;
    vector<int> a;
    for(int i = 0; i < n; i++) {
        int v;
        cin >> v;
        a.push_back(v);
    }
    int sellCharge;
    cin >> sellCharge;
    cout << stockExchange(a, sellCharge) << endl;
    vector<vector<int>> t(n+1, vector<int>(2, -1));
    cout << stockExchange(a, n, sellCharge, 0, t) << endl;
}