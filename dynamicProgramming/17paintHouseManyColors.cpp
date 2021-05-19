#include<bits/stdc++.h>
using namespace std;

int paintHouse(vector<vector<int>>& paintCost) {
    vector<int> dpo(paintCost[0].size(), 0);
    int fm = INT_MAX;
    int sm = INT_MAX;
    for(int j = 0; j < dpo.size(); j++) { //fill first row of paint cost of house1
        int v = paintCost[0][j];
        dpo[j] = v;
        if(v < fm) {
            sm = fm;
            fm = v;
        } else if(v < sm) {
            sm = v;
        }
    }
    for(int i = 1; i < paintCost.size(); i++) {
        vector<int> dpn;
        for(int j = 0; j < dpo.size(); j++) {
            int minCost;
            if(fm != dpo[j]) {
                minCost = paintCost[i][j] + fm;
            } else {
                minCost = paintCost[i][j] + sm;
            }
            dpn.push_back(minCost);
        }
        fm = INT_MAX, sm = INT_MAX;
        for(int j = 0; j < dpo.size(); j++) {
            int v = dpn[j];
            dpo[j] = v;
            if(v < fm) {
                sm = fm;
                fm = v;
            } else if(v < sm) {
                sm = v;
            }
        } 
    }
    return fm;
}

int main() {
    int n,k;
    cin >> n >> k;
    vector<vector<int>> a;
    for(int i = 0; i < n; i++) {
        vector<int> b;
        for(int j = 0; j < k; j++) {
            int v;
            cin >> v;
            b.push_back(v);
        }
        a.push_back(b);
    }
    cout << paintHouse(a) << endl;
    return 0;
}