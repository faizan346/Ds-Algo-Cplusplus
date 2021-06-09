#include<bits/stdc++.h>
using namespace std;

void substrCount(string s) {
    unordered_map<char, int> freqb;
    for(auto c : s) {
        if(freqb.count(c) == 0) {
            freqb[c] = 0;
        }
    }
    int count = 0;
    int ans = 0;
    int j = 0;
    for(int i = 0; i < s.size(); i++) {
        char c = s[i];
        if(freqb[c] == 0) count++;
        freqb[c]++;
        if(count > 1) {
            int n = i-j;
            ans += n*(n+1)/2;
            count = 1;
            freqb[s[j]] = 0;
            j = i;
        }
        if(i == s.size()-1 && count == 1) {
            int n = i-j+1;
            ans += n*(n+1)/2;
        }
    }
    cout << ans << endl;
}

void addToHashMap(unordered_map<char, int>& fre, char c) {
    if(fre.count(c) == 1) {
        fre[c]++;
    } else {
        fre[c] = 1;
    }
}

void removeFromHashMap(unordered_map<char, int>& fre, char c) {
    if(fre.count(c) == 1) {
        if(fre[c] > 1) fre[c]--;
        else fre.erase(c);
    }
}
void substrCount(string s, int k) {
    if(k == 1) {
        substrCount(s);
        return;
    }
    int n = s.size();
    unordered_map<char, int> freb;
    unordered_map<char, int> fres;
    int ib = -1;
    int is = -1;
    int j = -1;
    int ans = 0;
    while(true) {
        bool f1,f2,f3;
        f1 = f2 = f3 = false;
        while(ib < n-1) {
            f1 = true;
            ib++;
            char c = s[ib];
            addToHashMap(freb, c);
            if(freb.size() == k+1) {
                ib--;
                removeFromHashMap(freb, c);
                break;
            }
        }

        while(is < ib) {
            f2 = true;
            is++;
            char c = s[is];
            addToHashMap(fres, c);
            if(fres.size() == k) {
                is--;
                removeFromHashMap(fres, c);
                break;
            }
        }

        while(j < is && fres.size() == k-1 && freb.size() == k) {
            f3 = true;
            if(fres.size() == k-1 && freb.size() == k) {
                ans += ib - is;
            }
            j++;
            removeFromHashMap(fres, s[j]);
            removeFromHashMap(freb,s[j]);
        }
        
        if(f1 == false && f2 == false && f3 == false) {
            break;
        }
    }
    cout << ans << endl;
}

int main() {
    string s;
    cin >> s;
    int k;
    cin >> k;
    substrCount(s, k);
    return 0;
}