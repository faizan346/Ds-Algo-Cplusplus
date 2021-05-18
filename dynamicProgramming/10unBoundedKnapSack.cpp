#include<bits/stdc++.h>
using namespace std;

int UnBoundedknapSack(int n, int cap, vector<int>& w, vector<int>& val, vector<vector<int>>& t) {
    if(n == 0) {
        return 0;
    }
    if(cap <= 0) {
        return 0;
    }
    if(t[n][cap] != -1) return t[n][cap];

    int a = (cap >= w[n-1]) 
        ? UnBoundedknapSack(n, cap-w[n-1], w, val, t) + val[n-1] : 0;
    int b = UnBoundedknapSack(n-1, cap, w, val, t);
    return t[n][cap] = max(a, b);
}

int UnBoundedknapSack(int n, int cap, vector<int>& w, vector<int>& val) {
    vector<vector<int>> dp(n+1, vector<int>(cap+1, 0));
    for(int i = 1; i < dp.size(); i++) {
        for(int c = 1; c < dp[0].size(); c++) {
            //when we consider the item but also not exceeding the bad wt.
            //this time item can be reused.
            int a = (c >= w[i-1]) ? dp[i][c - w[i-1]] + val[i-1] : 0;
            //when we doens't consider the item
            int b = dp[i-1][c];
            dp[i][c] = max(a, b);
        }
    }
    return dp[n][cap];
}
// permutation type iteration or combination type iteration both works here
int UnBoundedknapSackOn(int n, int cap, vector<int>& w, vector<int>& val) {
    vector<int> dp(cap+1, 0); // each slot tell me the totalvalue i have for given cap.
    for(int c = 1; c < dp.size(); c++) { // we are gonna increase value by chosing optimal thing to put in each slot of bag.
        int m = 0;
        for(int i = 0; i < n; i++) {
            if(c - w[i] >= 0) {
                m = max(m, val[i] + dp[c - w[i]]);
            }
        }
        dp[c] = m;
    }
    return dp[cap];
}
// 5                                               
// 2 5 1 3 4
// 15 14 10 45 30
// 7
// 100
// 100

int main() {
    int n;
    cin >> n;
    vector<int> w;
    vector<int> val;
    for(int i = 0; i < n; i++) {
        int v;
        cin >> v;
        w.push_back(v);
    }
    for(int i = 0; i < n; i++) {
        int v;
        cin >> v;
        val.push_back(v);
    }
    int cap;
    cin >> cap;
    cout << UnBoundedknapSackOn(n, cap, w, val) << endl;
    cout << UnBoundedknapSack(n, cap, w, val) << endl;
    vector<vector<int>> t(n+1, vector<int>(cap+1, -1));
    cout << UnBoundedknapSack(n, cap, w, val, t) << endl;
    return 0;
}