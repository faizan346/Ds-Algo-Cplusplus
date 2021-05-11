#include<bits/stdc++.h>
using namespace std;


int main() {
    string s, sc;
    cin >> s;
    cin >> sc;
    unordered_map<char, int> umap;
    for(int i = 0; i < s.size(); i++) {
        if(umap.find(s[i]) == umap.end()) {
            umap[s[i]] = 1;
        }
    }

    for(auto c : sc) {
        if(umap.find(c) != umap.end()) {
            umap.erase(c);
            cout << c << " ";
        } 
    }
    cout << endl;
    return 0;
}