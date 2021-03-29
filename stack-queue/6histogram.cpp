#include<bits/stdc++.h>
using namespace std;


void nextGreaterElement(int *a, int n) {
    stack<int> s;
    int nser[n];
    int nsel[n];
    for(int i = n-1; i > -1; i--) { 
        while(!s.empty() && a[i] <= a[s.top()]) { 
            s.pop();
        }
        if(s.empty()) { 
            nser[i] = n;
        } else { 
            nser[i] = s.top();
        }
        s.push(i); 
    }

    for(int i = 0; i < n; i++) { 
        while(!s.empty() && a[i] <= a[s.top()]) { 
            s.pop();
        }
        if(s.empty()) { 
            nsel[i] = -1;
        } else { 
            nsel[i] = s.top();
        }
        s.push(i); 
    }

    int max = INT_MIN;
    for(int i = 0; i < n; i++) {
        int width = nser[i] - nsel[i] - 1;
        int area = width * a[i];
        if(max < area) max = area;
    }
    cout << max << endl;
   
}

// 7
// 6 2 5 4 5 1 6
// 12
int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
#endif
    int n;
    cin >> n;
    int a[n];
    for(int i = 0; i < n; i ++) {
        cin >> a[i];
    }
    nextGreaterElement(a, n);
    return 0;
}