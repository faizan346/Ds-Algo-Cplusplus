#include<bits/stdc++.h>
using namespace std;


int main() {
    int n;
    cin >> n;
    unordered_map<string, string> umap;
    for(int i = 0; i < n; i++) {
        string src, des;
        cin >> src >> des;
        umap[src] = des;
    }

    unordered_map<string, bool> source;
    for(auto x : umap) {
        string src = x.first;
        string des = x.second;
        source[des] = false;
        if(source.find(src) == source.end()) {
            source[src] = true;
        }
    }
    string realSource;
    for(auto x : source) {
        if(x.second == true) {
            realSource = x.first;
        }
    }
    while(true) {
        if(umap.find(realSource) != umap.end()) {
            cout << realSource << " -> ";
            realSource = umap[realSource];
        } else {
            cout << realSource << "." << endl;
            break;
        }
    }

    return 0;
}