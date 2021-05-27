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

bool validateStack1(vector<int>& push, vector<int>& pop) {
    int n = push.size();
    unordered_map<int, int> umap;
    int ind = 0;
    for(auto x : push) {
        umap[x] = ind++;
    }
    stack<int> st;
    st.push(pop[0]);
    for(int i = 1; i < n; i++) {
        int posa, posb;
        posa = umap[st.top()];
        st.push(pop[i]);
        posb = umap[st.top()];
        int s = st.size() - 2; // element not including curr two elements
        int diff = posa - posb - 1; // element between the given two positions.
        if(s < diff) { // as we know the elements in between should have already occured.. so size of stack much be greater or equal
            return false;
        }
    }
    return true;
}

bool validateStack2(vector<int>& push, vector<int>& pop) {
    int n = push.size();
    stack<int> st;
    int j = 0;
    for(int i = 0; i < n; i++) {
        st.push(push[i]);
        while(!st.empty() && pop[j] == st.top()) {
            st.pop();
            j++;
        }
    }
    return st.empty();
}

int main() {
    string s1, s2;
    getline(cin, s1);
    getline(cin, s2);
    vector<int> push, pop;
    fillArray(s1, push, s2, pop);
    
    cout << (validateStack2(push, pop) ? "true" : "false") << endl;

    return 0;
}