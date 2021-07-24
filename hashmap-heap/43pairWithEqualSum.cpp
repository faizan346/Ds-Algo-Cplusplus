#include<bits/stdc++.h>
using namespace std;

bool solve(vector<int> &a, int n) {
    unordered_set<int> us; // sum
    for(int i = 0; i < n; i++) {
        for(int j = i+1; j < n; j++) {
            if(us.count(a[i] + a[j]) == 1) return true;
            else us.insert(a[i] + a[j]);
        }
    }
    return false;
}

int main() {
    int n;
    cin >> n;
    vector<int> a(n, 0);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    cout << (solve(a, n) ? "true" : "false")<< endl;
    return 0;
}