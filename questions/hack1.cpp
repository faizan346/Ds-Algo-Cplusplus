#include<bits/stdc++.h>
using namespace std;

void solve1() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    int l, r;
    cin >> l >> r;
    int val = 0;
    int j = -1;
    int count = 0;
    for(int i = 0; i < n; i++) {
        char c = s[i];
        if(c == '1') {
            val = (val << 1 ) | 1;
        } else {
            val = val << 1;
        }
        while(j < i && (val > r || s[j+1] == '0')) {
            j++;
            int removeInd = i - j;
            val = val & ((1 << removeInd) - 1);
        }
        int temp = val;
        if(val >= l) {
            for(int k = j+1; k <= i; k++) {
                if(temp >= l && s[k] != '0') count++;
                if(temp < l) break;
                temp = temp & ~(1 << (i-k));
            }
        }
    }
    cout << count << endl; 
}
void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    int l, r;
    cin >> l >> r;
    int count = 0;
    for(int i = 0; i < n; i++) {
        if(s[i] == '0') continue;
        int val = 0;
        for(int j = 0; j < 32; j++) {
            if(i+j >= n) break;
            val = val << 1;
            val |= (int)(s[i+j] - '0');
            if(val > r) break;
            if(val >= l) count++;
        }
    }
    cout << count << endl;
}

int main() {
    int tc;
    cin >> tc;
    while(tc--) {
        solve();
    }
    return 0;
}