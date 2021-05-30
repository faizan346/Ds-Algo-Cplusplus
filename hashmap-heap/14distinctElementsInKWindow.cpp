#include<bits/stdc++.h>
using namespace std;


int main() {
    int n;
    cin >> n;
    int a[n];
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int k;
    cin >> k;

    vector<int> ans;
    
    unordered_map<int, int> umap;
    for(int i = 0; i < k - 1; i++) {
        if(umap.count(a[i] == 0)) {
            umap[a[i]] = 1;
        } else {
            umap[a[i]]++;
        }
    }
    for(int i = 0; i <= n-k; i++) {
        if(umap.count(a[i+k-1] == 0)) {
            umap[a[i+k-1]] = 1;
        } else {
            umap[a[i+k-1]]++;
        }
        ans.push_back(umap.size());
        umap[a[i]]--;
        if(umap[a[i]] == 0) {
            umap.erase(a[i]);
        }
    }
    for(auto x : ans) cout << x << " ";
    cout << endl;
    return 0;
}