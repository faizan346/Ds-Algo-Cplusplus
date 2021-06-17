#include<bits/stdc++.h>
using namespace std;

void nextGreaterRight(vector<int>& a, int n, vector<int>& nge) {
    stack<int> st;
    for(int i = n-1; i >= 0; i--) {
        while(!st.empty() && a[st.top()] < a[i]) {
            st.pop();
        }
        if(st.empty()) {
            nge[i] = -1;
        } else {
            nge[i] = st.top();
        }
        st.push(i);
    }
}

void nextGreaterLeft(vector<int>& a, int n, vector<int>& nge) {
    stack<int> st;
    for(int i = 0; i < n; i++) {
        while(!st.empty() && a[st.top()] <= a[i]) {
            st.pop();
        }
        if(st.empty()) {
            nge[i] = -1;
        } else {
            nge[i] = st.top();
        }
        st.push(i);
    }
}

int main() {
    int n;
    cin >> n;
    vector<int> a(n,0);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<int> nge(n, 0);
    nextGreaterRight(a, n, nge);
    vector<int> ngel(n, 0);
    nextGreaterLeft(a, n, ngel);
    
    vector<int> waterLevel(n, 0);
    int i = 0;
    while(i < n) {
        if(nge[i] != -1) {
            for(int k = i; k < nge[i]; k++) 
                waterLevel[k] = a[i];
            i = nge[i];
        } else {
            waterLevel[i] = a[i];
            i++;
        }
    }
    i = n-1;
    while(i >= 0) {
        if(ngel[i] != -1 ) {
            for(int k = i; k > ngel[i]; k--) 
                waterLevel[k] = max(waterLevel[k], a[i]);
            i = ngel[i];
        } else {
            i--;
        }
    }
    int ans = 0;
    for(int k = 0; k < n; k++) {
        ans += waterLevel[k] - a[k];
    }
    cout << ans << endl;
    return 0;
}