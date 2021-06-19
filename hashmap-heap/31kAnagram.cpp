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

string solve(string a, string b, int k) {
    if(a.size() != b.size()) return "false";
    unordered_map<char, int> frea,freb;
    for(auto c : a) {
        addMap(frea, c);
    }
    for(auto c : b) {
        addMap(freb, c);
    }
    int count = 0; // count of matching characters
    for(auto x : frea) {
        if(freb.count(x.first) == 1) {
            count += min(freb[x.first], x.second);
        }
    }
    // cout << b.size() << " " << count << endl;
    if(b.size() - count <= k) return "true";
    else return "false";
}

int main() {
    string a, b;
    cin >> a >> b;
    int k;
    cin >> k;
    cout << solve(a, b, k) << endl;
    return 0;
}