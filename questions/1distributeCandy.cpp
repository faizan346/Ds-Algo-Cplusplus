#include <bits/stdc++.h>
using namespace std;

void candy(vector<int> &A)
{
    vector<int> sol(A.size(), 1);
    for(int i = A.size() - 1; i > 0; i--) {
        if(A[i - 1] > A[i]) {
            sol[i - 1] = sol[i] + 1;
        }
    }
    for(int i = 0; i < A.size() - 1; i++) {
        if (A[i + 1] > A[i]) {
            sol[i + 1] = max((sol[i] + 1), sol[i + 1]);
        }
    }
    int sm = 0;
    for(int i = 0; i < A.size(); i++) { //cout<<sol[i]<<" ";
        sm += sol[i];
    }
    cout << sm << endl;
}

int main() {
    vector<int> v;
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        int inp;
        cin >> inp;
        v.push_back(inp);
    }
    candy(v);
    return 0;
}