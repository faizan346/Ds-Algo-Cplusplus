#include<bits/stdc++.h>
using namespace std;

int stockExchange(vector<int>& a, int n, int sc, int state, int gap, vector<vector<vector<int>>>& t) {
    if(n == 0 && state == 0) return 0;
    if(n == 0 && state == 1) return INT_MIN;
    if(t[n][state][gap] != -1) return t[n][state][gap];
    int profit = 0;
    if(state == 1) { // buy state
        profit = max(stockExchange(a, n-1, sc, 0, 0, t) - a[n-1], stockExchange(a, n-1, sc, 1, 1, t));
    } else { // sell state
        if(gap == 1) { // when there is gap between current sell and next buy
            profit = max(stockExchange(a, n-1, sc, 1, 1, t) + a[n-1] - sc, stockExchange(a, n-1, sc, 0, 1, t));
        } else {
            profit = stockExchange(a, n-1, sc, 0, 1, t);
        }
    }
    return t[n][state][gap] = profit;
}

int stockExchange(vector<int>& a, int sc) {
    int bs = -1*a[0]; // max profit when buyState
    int ss = 0; // max profit when soldState
    int cs = 0; // it stores the prevState of SoldState for coolDown soldstate.
    for(int i = 1; i < a.size(); i++) {
        int nbs, nss, ncs;
        nbs = max(bs, cs - a[i]);
        nss = max(ss, bs + a[i] - sc);
        ncs = ss;

        bs = nbs;
        ss = nss;
        cs = ncs;
    }
    return ss;
}

// 12
// 10 15 17 20 16 18 22 20 22 20 23 25
// 0
// 19

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
    vector<vector<vector<int>>> t(n+1, vector<vector<int>>(2, vector<int>(2,-1)));
    cout << stockExchange(a, n, sellCharge, 0, 1, t) << endl;
}