#include<bits/stdc++.h>
using namespace std;

void solve(vector<int> &a, int n) {
    int jump = 0;
    int i = 0;
    while(i < n) {
        int j = i;
        while(j < n-1) {
            if(a[j] >= a[j+1]) break;
            j++;
        }
        jump = max(jump, j - i);
        i = j+1;
    }
    cout << jump << endl;
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