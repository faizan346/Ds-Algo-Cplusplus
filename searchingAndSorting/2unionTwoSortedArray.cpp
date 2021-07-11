#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n, 0);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int m;
    cin >> m;
    vector<int> b(m, 0);
    for(int i = 0; i < m; i++) {
        cin >> b[i];
    }
    int i = 0;
    int j = 0;
    vector<int> ans;
    while(i < n && j < m) {
        if(a[i] < b[j]) {
            if(ans.empty() || ans.back() != a[i]) ans.push_back(a[i]);
            i++;
        } else if(a[i] > b[j]) {
            if(ans.empty() || ans.back() != b[j]) ans.push_back(b[j]);
            j++;
        } else {
            if(ans.empty() || ans.back() != a[i]) ans.push_back(a[i]);
            i++, j++;
        }
    }
    while(i < n) {
        if(ans.empty() || ans.back() != a[i]) ans.push_back(a[i]);
        i++;
    }
    while(j < m) {
        if(ans.empty() || ans.back() != b[j]) ans.push_back(b[j]);
        j++;
    }
    for(auto x : ans) cout << x << " ";
    cout << endl;
    return 0;
}