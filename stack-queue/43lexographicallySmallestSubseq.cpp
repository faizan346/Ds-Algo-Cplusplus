#include<bits/stdc++.h>
using namespace std;

vector<int> nextSmallestInteger(vector<int> &a) {
    vector<int> nse(a.size(), 0);
    stack<int> st;
    for(int i = a.size()-1; i >= 0; i--) {
        while(!st.empty() && a[st.top()] >= a[i]) {
            st.pop();
        }
        if(st.empty()) {
            nse[i] = a.size();
        } else {
            nse[i] = st.top();
        }
        st.push(i);
    }
    return nse;
}

int main() {
    int n;
    cin >> n;
    vector<int> a(n, 0);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int k;
    cin >> k;
    cout << k << endl;
    vector<int> nse = nextSmallestInteger(a);
    int i = 0;
    while(k > 0) {
        int r = n - k;
        while(nse[i] <= r) {
            i = nse[i];
        }
        cout << a[i] << endl;
        i++;
        k--;
    }
    return 0;
}

// 8

// 2
// 4
// 3
// 3
// 5
// 4
// 9
// 6

// 4
