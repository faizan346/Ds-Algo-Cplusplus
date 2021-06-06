#include<bits/stdc++.h>
using namespace std;

void nextGreaterInteger(vector<int>& a, vector<int>& ngel, int n) {
    stack<int> st;
    for(int i = 0; i < n; i++) {
        while(!st.empty() && a[i] >= a[st.top()]) {
            st.pop();
        }
        if(st.empty()) {
            ngel[i] = -1;
        } else {
            ngel[i] = st.top();
        }
        st.push(i);
    }
}

int main() {
    int n;
    cin >> n;
    vector<int> a(n, 0);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<int> ngel(n,0);
    nextGreaterInteger(a, ngel, n);
    vector<int> minVal(n, 0);
    minVal[0] = a[0];
    for(int i = 1; i < n; i++) {
        if(a[i] < minVal[i-1]) {
            minVal[i] = a[i];
        } else {
            minVal[i] = minVal[i-1];
        }
    }
    // i ran loop from right then find for ngel then took the min upto that
    // ngel and check if it is smaller than both large and middle of pattern
    int flag = false;
    for(int k = n-1; k >= 2; k--) {
        int mid = a[k];
        int li = ngel[k];
        if(li < 0) continue; // no index for smallest or li could be -1
        int large = a[li];
        int small = minVal[li];
        if(small >= large || small >= mid) continue;
        flag = true;
        break;
    }
    cout << ((flag) ? "true" : "false") << endl;
    return 0;
}