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
        } else {
            umap[s[i]]++;
        }
    }
    //this can't print more char than in sc array
    //so we limit sc according to our s array
    for(auto c : sc) {
        if(umap.find(c) != umap.end()) {
            if(umap[c] > 0) {
                 cout << c << " ";
                 umap[c]--;
            } else {
                umap.erase(c);
            }
        } 
    }
    cout << endl;
    return 0;
}