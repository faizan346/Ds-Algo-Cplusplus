#include<bits/stdc++.h>
using namespace std;

void solve(vector<int>& a, vector<int>& b) {
    int n = a.size();
    unordered_map<int, queue<int>> umap; // val, ind
    for(int i = 0; i < n; i++) {
        umap[a[i]].push(i);
    }
    for(auto x : b) {
        cout << umap[x].front() << " ";
        umap[x].pop();
    }
    cout << endl;
}

int main() {
    int n;
    cin >> n;
    vector<int> a(n, 0);
    vector<int> b(n, 0);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for(int i = 0; i < n; i++) {
        cin >> b[i];
    }
    
    solve(b, a);
    return 0;
}