#include<bits/stdc++.h>
using namespace std;
void addMap(unordered_map<char, int>& umap, char c) {
    if(umap.count(c) == 1) umap[c]++;
    else umap[c] = 1;
}

string mapToString(unordered_map<char, int>& fre) {
    vector<int> v(26, 0);
    for(auto x : fre) {
        v[x.first - 'a'] += x.second;
    }
    string res = "";
    for(int i = 0; i < 26; i++) {
        char c = i + 'a';
        res += c + to_string(v[i]);
    }
    return res;
}

int compareVV(vector<string>& v1, vector<string>& v2) {
    if(v1.size() != v2.size()) {
        return v1.size() > v2.size();
    }
    return v1[0].compare(v2[0]) < 0;
}

void display(unordered_map<string, vector<string>>& umap, vector<string>& keyOrder) {
    vector<vector<string>> res;
    for(auto key : keyOrder) {
        sort(umap[key].begin(), umap[key].end());
        res.push_back(umap[key]);
    }
    sort(res.begin(), res.end(), compareVV);
    for(auto y : res) {
        for(auto x : y) cout << x << " ";
        cout << endl;
    }
}

int main() {
    int n;
    cin >> n;
    vector<string> str(n,"");
    for(int i = 0; i < n; i++) {
        cin >> str[i];
    }
    unordered_map<string, vector<string>> umap;
    vector<string> keyOrder;
    for(auto s : str) {
        unordered_map<char, int> fre;
        for(auto c : s) {
            addMap(fre, c);
        }
        string StringKey = mapToString(fre);
        if(umap.count(StringKey) == 0) keyOrder.push_back(StringKey);
        umap[StringKey].push_back(s);
    }
    display(umap, keyOrder);
    return 0;
}