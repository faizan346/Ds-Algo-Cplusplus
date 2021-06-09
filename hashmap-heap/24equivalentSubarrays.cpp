#include<bits/stdc++.h>
using namespace std;

void addToMap(unordered_map<int, int>& fre, int x) {
    if(fre.count(x) == 1) {
        fre[x]++;
    } else {
        fre[x] = 1;
    }
}
void removeFromMap(unordered_map<int, int>& fre, int x) {
    if(fre.count(x) == 1) {
        if(fre[x] == 1) fre.erase(x);
        else fre[x]--;
    }
}

void solve(vector<int>& a, int n) {
    unordered_map<int, int> fre;
    for(auto x : a) {
        addToMap(fre, x);
    }
    int k = fre.size();
    fre.clear();
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
            addToMap(fre, x);
            if(fre.size() == k) {
                break;
            }
        }
        
        while(j < i && fre.size() == k) {
            f2 = true;
            ans += n - i;
            j++;
            removeFromMap(fre, a[j]);
        }
        
        if(f1 == false && f2 == false ) {
            break;
        }
    }
    cout << ans << endl;
}

int main() {
    int n;
    cin >> n;
    vector<int> a(n, 0);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    solve(a, n);
    return 0;
}