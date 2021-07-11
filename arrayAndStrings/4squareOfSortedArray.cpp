#include<bits/stdc++.h>
using namespace std;


int main() {
    int n;
    cin >> n;
    vector<int> a(n, 0);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int i = -1, j = -1;
    while(i < n) {
        i++, j++;
        if(a[i] >= 0) {
            j--;
            break;
        }
    }
    vector<int> ans;
    while(j >= 0 && i < n) {
        int si = a[i] * a[i];
        int sj = a[j] * a[j];
        if(si == sj) {
            ans.push_back(si);
            ans.push_back(sj);
            i++, j--;
        } else if(si < sj) {
            ans.push_back(si);
            i++;
        } else {
            ans.push_back(sj);
            j--;
        }
    }
    while(j >= 0) {
        int sj = a[j] * a[j];
        ans.push_back(sj);
        j--;
    }
    while(i < n) {
        int si = a[i] * a[i];
        ans.push_back(si);
        i++;
    }
    for(auto x : ans) cout << x << " ";
    cout << endl;
    return 0;
}