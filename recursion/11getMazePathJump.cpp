#include<bits/stdc++.h>
using namespace std;

vector<string> getMagePathJump(int i, int j, int n, int m) {
    if(i == n-1 && j == m-1) {
        vector<string> paths;
        paths.push_back("");
        return paths;
    }
    vector<string> hpaths;
    vector<string> vpaths;
    vector<string> dpaths;
    vector<string> paths;
    for(int k = j+1; k < m; k++) {
        hpaths = getMagePathJump(i, k, n, m); //get mpj for different value of k and safe it to the current solution
        for(auto s : hpaths) {
            s = (char)(k-j+'0') + s; 
            paths.push_back("h" + s);//adding the solution
        }
    }
    for(int k = i+1; k < n; k++) {
        vpaths = getMagePathJump(k, j, n, m);//same as above
        for(auto s : vpaths) {
            s = (char)(k-i+'0') + s;
            paths.push_back("v" + s);
        }
    }
    return paths;
}

void printMagePathJump(int i, int j, int n, int m, string print) {
    if(i == n-1 && j == m-1) {
        cout << print << endl;
        return;
    }
    for(int k = j+1; k < m; k++) {
        string s = "";
        s = (char)(k-j+'0') + s;
        s = 'h' + s;
        printMagePathJump(i, k, n, m, print + s); 
    }
    for(int k = i+1; k < n; k++) {
        string s = "";
        s = (char)(k-i+'0') + s;
        s = 'v' + s;
        printMagePathJump(k, j, n, m, print + s); 
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<string> s = getMagePathJump(0, 0, n, m);
    for(auto x : s) {
        cout << x << endl;
    }
    cout << endl;
    printMagePathJump(0, 0, n, m, "");
    return 0;
}