#include<bits/stdc++.h>
using namespace std;

vector<string> getMagePath(int i, int j, int n, int m) {
    if(i == n-1 && j == m-1) {
        vector<string> paths;
        paths.push_back("");
        return paths;
    }
    vector<string> hpaths;
    vector<string> vpaths;
    if(j+1 < m){
        hpaths = getMagePath(i, j+1, n, m);
    }
    if(i+1 < n){
        vpaths = getMagePath(i+1, j, n, m);
    }
    
    vector<string> paths;
    for(auto s : hpaths) {
        paths.push_back("h" + s);
    }
    for(auto s : vpaths) {
        paths.push_back("v" + s);
    }
    return paths;
}

void printMazePath(int i, int j, int n, int m, string print) {
    if(i == n-1 && j == m-1) {
        cout << print << endl;
        return;
    }
    if(j+1 < m) {
        printMazePath(i, j+1, n , m, print + "h");
    }
    if(i+1 < n) {
        printMazePath(i+1, j, n , m, print + "v");
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<string> s = getMagePath(0, 0, n, m);
    for(auto x : s) {
        cout << x << endl;
    }
    cout << endl;
    printMazePath(0,0, n,m, "");
    return 0;
}