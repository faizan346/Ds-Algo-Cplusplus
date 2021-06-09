#include<bits/stdc++.h>
using namespace std;


void solve(vector<int>& a, int n, int k) {
    unordered_map<int, int> fre;
    fre[0] = 0;
    fre[1] = 0;
    int j = -1;
    int i = -1;
    int ans = 0;
    while(true) {
        bool f1, f2;
        f1 = f2 = false;
        while(i < n-1) {
            f1 = true;
            i++;
            int x = a[i];
            fre[x]++;
            if(fre[0] == k+1) {
                break;
            } else {
                ans = max(ans, i-j);
            }
        }
        
        while(j < i && fre[0] == k+1) {
            f2 = true;
            j++;
            fre[a[j]]--;
            if(fre[0] == k) ans = max(ans, i-j);
        }
        
        if(f1 == false && f2 == false) {
            break;
        }
    }
    cout << ans;
}

int main() {
    int n;
    cin >> n;
    vector<int> a(n, 0);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int k;
    cin >> k;
    solve(a, n, k);
    return 0;
}