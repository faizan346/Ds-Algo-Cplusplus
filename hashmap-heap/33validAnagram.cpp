#include<bits/stdc++.h>
using namespace std;

void addMap(unordered_map<char, int>& umap, char c) {
    if(umap.count(c) == 1) umap[c]++;
    else umap[c] = 1;
}

void removeMap(unordered_map<char, int>& umap, char c) {
    if(umap.count(c) == 1) {
        if(umap[c] > 1) umap[c]--;
        else umap.erase(c);
    }
}

bool solve(string a, string b) {
    if(a.size() != b.size()) return false;
    unordered_map<char, int> frea, freb;
    for(auto c : a) {
        addMap(frea, c);
    }
    for(auto c : b) {
        addMap(freb, c);
    }
    for(auto x : frea) {
        if(freb.count(x.first) == 0 || x.second != freb[x.first]) return false;
    }
    return true;
}

int main() {
    string a, b;
    cin >> a >> b;
    cout << (solve(a, b) ? "true" : "false") << endl;
    return 0;
}