#include<bits/stdc++.h>
using namespace std;


int main() {
    int n;
    cin >> n;
    vector<int> a(n, 0);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int x, k;
    cin >> x >> k;
    
    int i = 0, j = n-1;
    while(i <= j) {
        int mid = (i+j)/2;
        if(a[mid] == k) {
            i = mid+1;
            j = mid-1;
            break;
        } else if(a[mid] < k) {
            i = mid+1;
        } else {
            j = mid-1;
        }
    }
    vector<int> ans;
    while(x-- > 0) {
        if(i <= n-1 && j >= 0) {
            ans.push_back((abs(a[j] - k) <= abs(a[i] - k)) ? a[j] : a[i]);
            j--, i++;
        } else if(i <= n-1) {
            ans.push_back(a[i]);
            i++;
        } else if(j >= 0) {
            ans.push_back(a[j]);
            j--;
        }
    }
    for(auto x : ans) cout << x << " ";
    cout << endl;
    return 0;
}