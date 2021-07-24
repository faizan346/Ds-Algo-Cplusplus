#include<bits/stdc++.h>
using namespace std;

vector<int> majority(vector<int> &a, int n, int k) {
    vector<int> res;
    unordered_map<int, int> umap;
    for(auto x : a) {
        if(umap.count(x) == 0) umap[x] = 0;
        umap[x]++;
    }
    for(auto x : umap) {
        if(x.second > n/k) res.push_back(x.first);
    }
    return res;
}

int main() {
    int n;
    cin >> n;
    vector<int> a(n, 0);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int k;
    cin >> k;
    vector<int> majArr = majority(a, n, k);
    sort(majArr.begin(), majArr.end());
    cout << "[";
    for(int i = 0; i < majArr.size(); i++) {
        cout << majArr[i];
        if(i != majArr.size()-1) {
            cout << ", ";
        }
    }
    cout << "]" << endl;
    return 0;
}