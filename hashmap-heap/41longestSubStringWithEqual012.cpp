#include<bits/stdc++.h>
using namespace std;

int solve(vector<int> &a, int n) {
    unordered_map<string ,int> diff;
    diff["0#0"] = -1; // diff10#diff21, ind
    int fre[3];
    fre[0] = 0, fre[1] = 0, fre[2] = 0; // stores fre for 0 1 2
    int len = 0;
    for(int i = 0; i < n; i++) {
        fre[a[i]]++;
        int d10 = fre[1] - fre[0];
        int d21 = fre[2] - fre[1];
        string s = to_string(d10) + "#" + to_string(d21);
        if(diff.count(s) == 0) {
            diff[s] = i;
        } else {
            len = max(len, i - diff[s]);
        }
    }
    return len;
}

int main() {
    int n;
    cin >> n;
    vector<int> a(n, 0);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    cout << solve(a, n) << endl;
    return 0;
}