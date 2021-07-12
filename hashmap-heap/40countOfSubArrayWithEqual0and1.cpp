#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n, 0);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    unordered_map<int, int> umap; // sum, count
    umap[0] = 1; // when no elements
    int count = 0;
    int sum = 0;
    for(int i = 0; i < n; i++) {
        if(a[i] == 1) {
            sum++;
        } else {
            sum--;
        }
        if(umap.count(sum) == 0) {
            umap[sum] = 1;
        } else {
            count += umap[sum];
            umap[sum]++;
        }
    }
    cout << count << endl;
    return 0;
}