#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n, 0);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    unordered_map<int, int> umap; // (sum, ind)
    int longest = 0;
    umap[0] = -1;
    int sum = 0;
    for(int i = 0; i < n; i++) {
        sum += a[i];
        if(umap.count(sum)) {
            longest = max(longest, i - umap[sum]);
        } else {
            umap[sum] = i;
        }
    }
    cout << longest << endl;    
    return 0;
}