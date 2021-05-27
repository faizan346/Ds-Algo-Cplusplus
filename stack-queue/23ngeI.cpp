#include<bits/stdc++.h>
using namespace std;

// input helper functions ==> Start
int toInt(string s) {
    int d = 1;
    int num = 0;
    for(int i = s.size()-1; i>=0; i--){
        num += (s[i] - '0') * d;
        d = d * 10;
    }
    return num;
}

void fillArray(string& s1, vector<int>& q, string& s2, vector<int>& n) {
    stringstream ss1(s1);
    stringstream ss2(s2);
    string word;
    while(ss1 >> word) {
        q.push_back(toInt(word));
    }
    while(ss2 >> word) {
        n.push_back(toInt(word));
    }
}
// input helper functions ==> End


int main() {
    string s1, s2;
    getline(cin, s1);
    getline(cin, s2);
    vector<int> query, num;
    fillArray(s1, query, s2, num);

    unordered_map<int, int> umap; //(num, nge);
    stack<int> st;
    for(int i = num.size()-1; i >= 0; i--) {
        while(!st.empty() && st.top() <= num[i]) {
            st.pop();
        }
        if(st.empty()) {
            umap[num[i]] = -1;
        } else {
            umap[num[i]] = st.top();
        }
        st.push(num[i]);
    }
    cout << query.size() << endl;
    for(auto x : query) {
        cout << umap[x] << endl;
    }

    return 0;
}