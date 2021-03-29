#include<bits/stdc++.h>
using namespace std;

const string codes[] = {".;", "abc", "def","ghi","jkl", "mno", "pqrs", "tu", "vwx","yz"};

vector<string> getKpc(string s) {
    if(s.size() == 0) {
        vector<string> mres;
        mres.push_back("");
        return mres;
    }
    //678
    char c = s[0]; //6
    string rem = s.substr(1);//78
    vector<string> res = getKpc(rem); //6 words of 78
    vector<string> mres; //24 words of 678
    for(auto ch : codes[c - '0']) {
        for(auto x : res) {
            mres.push_back(ch + x);
        }
    }

    return mres;
}

void printKpc(string s, string print) {
    if(s.size() == 0) {
        cout << print << " ";
        return;
    }
     //678
    char c = s[0]; //6
    string rem = s.substr(1);//78
    for(auto ch : codes[c - '0']) {
        printKpc(rem, print + ch);
    }
}

int main() {
    string str;
    cin >> str;
    vector<string> s = getKpc(str);
    for(auto x : s) {
        cout << x << " ";
    }
    cout << endl;
    string print = "";
    printKpc(str, print);
    cout << endl;
    return 0;
}