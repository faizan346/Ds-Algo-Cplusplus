#include<bits/stdc++.h>
using namespace std;

int paintHouse(vector<vector<int>>& paintCost, int n, int color, vector<vector<int>>& t) {
    if(n == 0) return 0;
    if(t[n][color] != -1) return t[n][color];
    int cost;
    if(color == 0) {
        cost = min(min(paintHouse(paintCost, n-1, 1, t) + paintCost[n-1][0]
            , paintHouse(paintCost, n-1, 2, t) + paintCost[n-1][1])
            , paintHouse(paintCost, n-1, 3, t) + paintCost[n-1][2]);
    } else if(color == 1) {
        cost = min(paintHouse(paintCost, n-1, 2, t) + paintCost[n-1][1]
            , paintHouse(paintCost, n-1, 3, t) + paintCost[n-1][2]);
    } else if(color == 2){
        cost = min(paintHouse(paintCost, n-1, 1, t) + paintCost[n-1][0]
            , paintHouse(paintCost, n-1, 3, t) + paintCost[n-1][2]);
    } else if(color == 3){
        cost = min(paintHouse(paintCost, n-1, 1, t) + paintCost[n-1][0]
            , paintHouse(paintCost, n-1, 2, t) + paintCost[n-1][1]);
    }
    return t[n][color] = cost;
}
// dry run is for cost max by mistake so review it that way
int paintHouse(vector<vector<int>>& paintCost) {
    int n = paintCost.size();
    int ro = 0;
    int bo = 0;
    int go = 0;
    for(int i = 0; i < n ; i++) {
        int r,b,g;
        r = min(bo, go) + paintCost[i][0];
        b = min(ro, go) + paintCost[i][1];
        g = min(ro, bo) + paintCost[i][2];
        ro = r;
        bo = b;
        go = g;
    }
    return min(min(ro, bo), go);
}

int main() {
    int n;
    cin >> n;
    vector<vector<int>> a;
    for(int i = 0; i < n; i++) {
        vector<int> v;
        int r, b, g;
        cin >> r >> b >> g;
        v.push_back(r);
        v.push_back(b);
        v.push_back(g);
        a.push_back(v);
    }
    cout << paintHouse(a) << endl;
    vector<vector<int>> t(n+1, vector<int>(4, -1));
    cout << paintHouse(a, n, 0, t) << endl;
    return 0;
}