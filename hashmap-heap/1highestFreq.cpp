#include<bits/stdc++.h>
using namespace std;


int main() {
    string s;
    cin >> s;
    unordered_map<char, int> umap;
    for(int i = 0; i < s.size(); i++) {
        if(umap.find(s[i]) == umap.end()) {
            umap[s[i]] = 1;
        } else {
            umap[s[i]]++;
        }
    }
    char ans = s[0];
    for(auto p : umap) {
        if(p.second > umap[ans]) {
            ans = p.first;
        }
    }
    cout << ans << endl;
    return 0;
}