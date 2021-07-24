#include<bits/stdc++.h>
using namespace std;

string solve(string &s) {
    int n = s.size();
    int swapi = -1;
    for(int i = n-2; i >= 0; i--) {
        if(s[i] < s[i+1]) {
            swapi = i;
            break;
        }
    }
    if(swapi == -1) return "-1";
    int swapj;
    for(int i = n-1; i > swapi; i--) {
        if(s[swapi] < s[i]) {
            swapj = i;
            break;
        }
    }
    swap(s[swapi], s[swapj]);
    reverse(s.begin() + swapi+1, s.end());
    return s;
}

int main() {
    string s;
    cin >> s;
    cout << solve(s) << endl;
    return 0;
}