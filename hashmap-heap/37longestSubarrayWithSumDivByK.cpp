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
    unordered_map<int, int> umap; // rem, ind;
    umap[0] = -1;
    int sum = 0;
    int len = 0;
    for(int i = 0; i < n; i++) {
        sum += a[i];
        int rem = sum % k;
        if(rem < 0) rem = rem + k;
        if(umap.count(rem) == 0) {
            umap[rem] = i;
        }
        len = max(len, i - umap[rem]);
    }
    cout << len << endl;
    return 0;
}