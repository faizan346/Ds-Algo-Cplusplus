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
    unordered_map<int, int> umap; // rem, count
    umap[0] = 1; // initially when zero elements
    int count = 0;
    int sum = 0;
    for(int i = 0; i < n; i++) {
        sum += a[i];
        int rem = sum % k;
        if(rem < 0) rem += k;
        if(umap.count(rem) == 0) {
            umap[rem] = 1;
        } else {
            count += umap[rem]; // as it can make remOccurance-1 pair 
            umap[rem]++;
        }
    }
    cout << count << endl;
    return 0;
}