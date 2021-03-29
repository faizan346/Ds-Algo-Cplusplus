#include<bits/stdc++.h>
using namespace std;

vector<string> getStairsPath(int n) {
    if(n == 0) {
        vector<string> mres;
        mres.push_back("");
        return mres;
    }
    vector<string> mres;
    for(int i = 1; i <= n; i++) {
        vector<string> res = getStairsPath(n-i);
        for(auto x : res) {
            mres.push_back((char)(i+'0') + x);
        }
    }
    return mres;
}

void printStairsPath(int n, string path) {
    if(n == 0) {
        cout << path << " ";
        return;
    }
    for(int i = 1; i <= n; i++) {
        printStairsPath(n-i,(char)(i+'0')+path);
    }
}

int main() {
    int n;
    cin >> n;
    vector<string> s = getStairsPath(n);
    for(auto x : s) {
        cout << x << " " ;
    }
    cout << endl;
    string path = "";
    printStairsPath(n,path);
    cout << endl;
    return 0;
}