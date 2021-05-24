#include<bits/stdc++.h>
using namespace std;

vector<string> printGrayCode(int n) {
    if(n == 0) {
        return vector<string>(1, "");
    }
    vector<string> res = printGrayCode(n-1);
    vector<string> mres;
    for(auto s : res) {
        mres.push_back('0' + s);
    }
    for(int i = res.size()-1; i >= 0; i--) {
        mres.push_back('1' + res[i]);
    } 
    return mres;

}

 vector<int> grayCode(int n) {
    if(n == 0) {
        return vector<int>();
    }
 	if(n == 1) {
         return vector<int>({0,1});
    }
    vector<int> res = grayCode(n-1);
    vector<int> mres;
    for(auto s : res) {
        mres.push_back(s);
    }
    for(int i = res.size()-1; i >= 0; i--) {
        mres.push_back(res[i] | (1 << (n-1)));
    } 
    return mres;
 }

int main() {
    int n;
    cin >> n;
    vector<string> s = printGrayCode(n);
    for(auto x : s) cout << x << " ";
    vector<int> v = grayCode(n);
    cout << endl;
    for(auto x : v) cout << x << " ";
    cout << endl;
    return 0;
}