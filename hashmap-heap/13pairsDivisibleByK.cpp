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
    
    unordered_map<int, int> umap; // stores remainder freq..

    for(int i = 0; i < n; i++) {
        if(umap.find(a[i] % k) == umap.end()) {
            umap[a[i] % k] = 0;
        }
        umap[a[i] % k]++;
    }
    string ans = "true";
    for(auto x : umap) {
        int rem = x.first;
        int freq = x.second;
        if(freq > 0) {  
            int diff;
            if(rem == 0) diff = 0;
            else diff = k - rem;
            if(umap.find(diff) != umap.end() && umap[diff] > 0) {
                umap[diff]--;
                umap[rem]--;
            } else {
                ans = "false";
                break;
            }
        }
    }
    cout << ans << endl;
    return 0;
}