#include<bits/stdc++.h>
using namespace std;

// byte -> 1, 2, 3, 4
// 1 -> 0-------
// 2 -> 110----- 10------
// 3 -> 1110---- 10------ 10------
// 4 -> 11110--- 10------ 10------ 10------

int checkState(int n) {
    int m7 = 1<<7;
    int m6 = 1<<6;
    int m5 = 1<<5;
    int m4 = 1<<4;
    int m3 = 1<<3;
    if((n & m7) == 0) return 1; // 0
    if((n & m6) == 0) return 0; // 10
    if((n & m5) == 0) return 2; // 110
    if((n & m4) == 0) return 3; // 1110
    if((n & m3) == 0) return 4; // 11110
}

string utf8Encoding(vector<int>& a, int n) {
    int preState = 1;
    for(auto x : a) {
        int xState = checkState(x);
        if(xState == 0) {
            if(preState > 1) {
                preState--;
            } else {
                return "false";
            }
        } else {
            if(preState == 1) {
                preState = xState;
            } else {
                return "false";
            }
        }
    }
    return "true";
}

int main() {
    int n;
    cin >> n;
    vector<int> a(n, 0);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    cout << utf8Encoding(a, n);
    
    return 0;
}