#include<bits/stdc++.h>
using namespace std;

vector<string> generateParenthesis(int n) {
    if(n == 0) {
        vector<string> mres;
        mres.push_back("");
        return mres;
    }
    vector<string> res = generateParenthesis(n-1);
    vector<string> mres;
    for(auto s : res) {
        bool flag = true;
        string t = "()" + s;
        for(auto x : res) {
            if(x == t) 
                flag = false;
        }
        if(flag) 
            mres.push_back(t);
    }
    for(auto s: res) {
        bool flag = true;
        string t = "(" + s + ")";
        for(auto x : res) {
            if(x == t) 
                flag = false;
        }
        if(flag) 
            mres.push_back(t);
    }
    for(auto s : res) {
        bool flag = true;
        string t = s + "()";
        for(auto x : res) {
            if(x == t) 
                flag = false;
        }
        if(flag) 
            mres.push_back(t);
    }
    return mres;
}

int main() {
    int n;
    cin >> n;
    generateParenthesis(n);
    return 0;
}