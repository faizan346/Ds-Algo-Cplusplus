#include<bits/stdc++.h>
using namespace std;

void solve(string s) {
    int n = s.size();
    unordered_map<char, int> fre; 
    unordered_map<char, int> freWin;
    int fcount = 0;
    for(auto c : s) {
        if(fre.count(c) == 0) {
            fre[c] = 1;
            freWin[c] = 0;
            fcount++;
        }
    }
    int count = 0;
    int len = INT_MAX;
    int i = 0, j = 0;
    while(true) {
        bool f1 = false, f2 = false;
        //acquire
        while(i < n && count < fcount) {
            char c = s[i];
            if(fre.count(c) == 1) {
                if(freWin[c] < fre[c]) count++;
                freWin[c]++;
            }
            i++;
            f1 = true;
        }
        //collect potential answer and release
        while(j <= i && count == fcount) {
            char c = s[j];
            if(len > (i-1 - j + 1)) { //pot ans vs actual ans
               len = i - j;
            }
            if(fre.count(c) == 1) {
                freWin[c]--;
                if(freWin[c] < fre[c]) count--;
            }
            j++;
            f2 = true;
        }
        if(f1 == false && f2 == false) {
            break;
        }
    }
    cout << len << endl;
}

int main() {
    string s;
    cin >> s;
    solve(s);
}