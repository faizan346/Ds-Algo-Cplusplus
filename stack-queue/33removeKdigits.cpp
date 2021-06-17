#include<bits/stdc++.h>
using namespace std;

void nextSmallest(string s, vector<int>& nge, int n) {
    stack<int> st;
    for(int i = n-1; i >= 0; i--) {
        while(!st.empty() && s[i] <= s[st.top()]) {
            st.pop();
        }
        if(st.empty()) {
            nge[i] = n;
        } else {
            nge[i] = st.top();
        }
        st.push(i);
    }
}

void solve1(string s, int k, int n) {
    vector<int> nse(n, 0);
    nextSmallest(s, nse, n);
    
    string ans = "";
    int i = 0;
    int j = 0;
    while(i < n && k != n) {
        j = i;
        while(nse[j] <= k) {
            j = nse[j];
        }
        k++;
        ans += s[j];
        i = j+1;
    }
    
    for(i = 0; i < ans.size(); i++) {
        if(ans[i] != '0') {
            break;
        }
    }
    ans = ans.substr(i);
    if(ans == "") cout << 0 << endl;
    else cout << ans << endl;
}

void solve2(string s, int n, int k) {
    stack<char> st;
    for(auto d : s) {
        // elimating pre digit if greater than curr digit in stack
        // till k > 0 as that would lead to smaller digit as we making 
        // msb smaller
        while(!st.empty() && st.top() > d && k > 0) {
            st.pop();
            k--;
        }
        st.push(d);
    }
    string ans = "";
    while(!st.empty()) {
        ans = st.top() + ans;
        st.pop();
    }
    ans = ans.substr(0, ans.size()-k);
  
    int i;
    for(i = 0; i < ans.size(); i++) {
        if(ans[i] != '0') {
            break;
        }
    }
    ans = ans.substr(i);
    if(ans == "") cout << 0 << endl;
    else cout << ans << endl;
    
}

int main() {
    string s;
    cin >> s;
    int k;
    cin >> k;
    int n = s.size();
    //solve1(s, k, n);
    solve2(s, n, k);
    return 0;
}