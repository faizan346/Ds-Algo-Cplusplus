#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n, 0);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int k;
    cin >> k;
    
    int count = 0;
    int sum = 0;
    unordered_map<int, int> umap; // sum freq 
    umap[0] = 1;
    for(int i = 0; i < n; i++) {
        sum += a[i];
        if(umap.count(sum) == 0) umap[sum] = 1;
        else umap[sum]++;
        if(umap.count(sum-k) == 1) {
            count += umap[sum-k];
        }
    }
    cout << count << endl;
    return 0;
}