#include<bits/stdc++.h>
using namespace std;

void nextSmallestRight(vector<int>& a, int n, vector<int>& nser) {
    stack<int> st;
    for(int i = n-1; i >= 0; i--) {
        while(!st.empty() && a[i] <= a[st.top()]) {
            st.pop();
        }
        if(st.empty()) {
            nser[i] = n;
        } else {
            nser[i] = st.top();
        }
        st.push(i);
    }
}

void nextSmallestLeft(vector<int>& a, int n, vector<int>& nsel) {
    stack<int> st;
    for(int i = 0; i < n; i++) {
        while(!st.empty() && a[i] <= a[st.top()]) {
            st.pop();
        }
        if(st.empty()) {
            nsel[i] = -1;
        } else {
            nsel[i] = st.top();
        }
        st.push(i);
    }
}
void histogramOld(vector<int>& a, int n) {
    vector<int> nser(n, 0);
    vector<int> nsel(n, 0);
    
    nextSmallestRight(a, n, nser);
    nextSmallestLeft(a, n, nsel);
    
    int area = 0;
    for(int i = 0; i < n ;i++) {
        int width = nser[i] - nsel[i] - 1;
        area = max(area, width*a[i]);
    }
    cout << area << endl;
}

// we can wind left and right next smallest or greatest in one iteration
// as when we pop actually it is the opposite condition. but beware of equal condition
void histogram(vector<int> a, int n) {
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
    cout << area << endl;
}

int main() {
    int n;
    cin >> n;
    vector<int> a(n, 0);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    //histogramOld(a, n);
    histogram(a, n);
    return 0;
}