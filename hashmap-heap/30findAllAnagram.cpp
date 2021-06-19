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

int main() {
    string a, b;
    cin >> a >> b;
    unordered_map<char, int> freb;
    unordered_map<char, int> frea;
    for(auto c : b) {
        addMap(freb, c);
    }
    int count = 0;
    vector<int> v;
    int j = -1;
    for(int i = 0; i < a.size(); i++) {
        char c = a[i];
        addMap(frea, c);
        if(freb.count(c) == 0) { // if window have ch which is not part of b jump window to it front
            frea.clear();
            j = i;
        } else {
            while(j < i && frea[c] > freb[c]) { // if freq count gets bigger release from back
                j++;
                removeMap(frea, a[j]);
            }
            if(i - j == b.size()) { // if window size equal to length of b string
                count++;
                v.push_back(j+1);
            }
        }
    }
    
    cout << count << endl;
    for(auto x : v) cout << x << " ";
    cout << endl;
    return 0;
}












