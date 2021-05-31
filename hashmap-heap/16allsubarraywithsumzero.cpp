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
    int count = 0;
    umap[0] = -1;
    int sum = 0;
    for(int i = 0; i < n; i++) {
        sum += a[i];
        if(umap.count(sum)) {
            count += umap[sum];
            umap[sum]++;
        } else {
            umap[sum] = 1;
        }
    }
    cout << count << endl;    
    return 0;
}
