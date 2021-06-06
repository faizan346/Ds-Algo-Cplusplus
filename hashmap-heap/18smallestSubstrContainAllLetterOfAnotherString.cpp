#include<bits/stdc++.h>
using namespace std;

void solve(string s, string sm) {
    int n = s.size();
    unordered_map<char, int> fre; 
    unordered_map<char, int> freWin;
    for(auto c : sm) {
        if(fre.count(c) == 1) {
            fre[c]++;
        } else {
            fre[c] = 1;
            freWin[c] = 0;
        }
    }
    int fcount = sm.size();
    int count = 0;
    int aj = -1, ai = -1;
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
            if(aj == -1 || (ai - aj) > ((i-1) - j)) { //pot ans vs actual ans
                ai = i-1; // because i is one ch ahead because of above loop
                aj = j;
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
    if(aj == -1) {
        cout << "" << endl;
        return;
    } 
    cout << s.substr(aj, ai-aj+1) << endl;
}

int main() {
    string s, sm;
    cin >> s >> sm;
    solve(s, sm);
}