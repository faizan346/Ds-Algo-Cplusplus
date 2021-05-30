#include<bits/stdc++.h>
using namespace std;

int getSize(unordered_map<string, unordered_set<string>>& tree, 
    string man, unordered_map<string, int>& result) {

        int size = 0;
        if(tree.find(man) != tree.end()) { // if false means no child..
            for(auto x : tree[man]) {
                size += getSize(tree, x, result);
            }
        }
        result[man] = size;
        return size + 1;
}

void numOfEmployee(unordered_map<string, string> umap) {
    unordered_map<string, unordered_set<string>> tree;
    string ceo = "";
    for(auto x : umap) {
        string emp = x.first;
        string man = x.second;
        if(man == emp) {
            ceo = man;
        } else if(tree.find(man) == tree.end()) {
            unordered_set<string> uset;
            uset.insert(emp);
            tree[man] = uset;
        } else {
            tree[man].insert(emp);
        }
    }
    unordered_map<string, int> result;
    getSize(tree, ceo, result);
    for(auto x : result) {
        cout << x.first << " " << x.second << endl;
    }
}

int main() {
    int n;
    cin >> n;
    unordered_map<string, string> umap;
    for(int i = 0; i < n; i++) {
        string emp, man;
        cin >> emp >> man;
        umap[emp] = man;
    }
    numOfEmployee(umap);

    return 0;
}