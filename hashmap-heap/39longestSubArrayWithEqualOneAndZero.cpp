#include<bits/stdc++.h>
using namespace std;


int main() {
    int n;
    cin >> n;
    vector<int> a(n, 0);
    for(int i = 0; i< n; i++) {
        cin >> a[i];
    }
    unordered_map<int, int> umap; // sum, ind
    int sum = 0;
    umap[0] = -1;
    int len = 0;
    for(int i = 0; i < n; i++) {
        if(a[i] == 1) {
            sum++;
        } else { // consider 0 as -1
            sum--;
        }
        if(umap.count(sum) == 0) {
            umap[sum] = i;
        }
        len = max(len, i - umap[sum]);
    }
    cout << len << endl;
    return 0;
}