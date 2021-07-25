#include<bits/stdc++.h>
using namespace std;

void solve(vector<int> &a, int n) {
    int par = 0;
    int upToInd = 0;
    for(int i = 0; i < n; i++) {
        if(upToInd < a[i]) {
            upToInd = a[i]; // we have to atleast sort upto this ind to get partition sorted.
        } 
        if(upToInd == i) { // reaches the partition end.
            par++;
            upToInd = 0; // it help to update uptoInd for next partition
        }
    }
    cout << par << endl;
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