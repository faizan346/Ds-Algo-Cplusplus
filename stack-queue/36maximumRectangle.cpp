#include<bits/stdc++.h>
using namespace std;

int histogramArea(vector<int> a) {
    for(auto x : a) cout << x << " " ;
    cout << endl;
    int n = a.size();
    int area = 0;
    a.push_back(0);
    stack<int> st;
    st.push(-1);
    for(int i = 0; i <= n; i++) {
        while(st.top() != -1 && a[i] <= a[st.top()]) {
            int height = a[st.top()];
            st.pop();
            int rightMin = i;
            int leftMin = st.top();
            area = max(area, height*(rightMin-leftMin-1));
        }
        st.push(i);
    }
    return area;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> h(n, vector<int>(m, 0)); // histogram 2d
    for(int i = 0; i < n; i++) {
        string s;
        cin >> s;
        for(int j = 0; j < s.size(); j++) {
            h[i][j] = s[j] - '0';
            if(i > 0 && h[i][j] == 1) {
                h[i][j] += h[i-1][j];
            }
        }
    }
    int area = 0;
    for(int i = 0; i < n; i++) {
        area = max(area, histogramArea(h[i]));
    }
    cout << area << endl;
    return 0;
}