#include<bits/stdc++.h>
using namespace std;
int countRun = 0;

long long getNum(string& s,unordered_map<char, int>& umap) {
    long long dig = 1;
    long long num = 0;
    for(int i = s.size()-1; i >= 0; i--) {
        num += dig * umap[s[i]];
        dig *= 10;
    }
    return num;
}


void printCom(string &a, string& b, string& c, string& s, int ind, 
                unordered_map<char, int>& umap, vector<bool>& visNum) {
    countRun++;
    if(ind == s.size()) {
        long long numa = getNum(a, umap);
        long long numb = getNum(b, umap);
        long long numc = getNum(c, umap);
        if(numa + numb == numc) {
            for(char ch = 'a'; ch <= 'z'; ch++) {
                if(umap.count(ch) == 1) {
                    cout << ch << "-" << umap[ch] << " ";
                }
            }
            cout << endl;
        }
        return;
    }
    for(int i = 0; i <= 9; i++) {
        if(visNum[i]) continue;
        umap[s[ind]] = i;
        visNum[i] = true;
        printCom(a,b,c,s,ind+1,umap,visNum);
        umap[s[ind]] = -1;
        visNum[i] = false;
    }
}

int main() {
    string a, b, c;
    cin >> a >> b >> c;
    unordered_map<char, int> umap; // char, dig;
    vector<bool> visNum(10, false); 
    string s = "";
    
    for(auto x : a) {
        if(umap.count(x) == 0) s += x;
        umap[x] = -1;
    }
    for(auto x : b) {
        if(umap.count(x) == 0) s += x;
        umap[x] = -1;
    }
    for(auto x : c) {
        if(umap.count(x) == 0) s += x;
        umap[x] = -1;
    }
    printCom(a, b, c, s, 0, umap, visNum);
    cout << countRun ;
}