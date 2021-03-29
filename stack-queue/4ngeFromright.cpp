#include<bits/stdc++.h>
using namespace std;
//pop,store than push
void nextGreaterElement(int *a, int n) {
    stack<int> s;
    int nge[n];
    for(int i = 0; i < n; i++) {
        // curr element is nge for all small element in stack
        while(!s.empty() && a[i] > a[s.top()]) { 
            nge[s.top()] = a[i];
            s.pop();
        }

        s.push(i); //nge may find this if it has nge.
    }
    //all rem element has no nge.
    while(!s.empty()) {
        nge[s.top()] = -1;
        s.pop();
    }

    for(int x : nge) cout << x << " ";
    cout << endl;
}

//9
//2 5 9 3 1 12 6 8 7
//5 9 12 12 12 -1 8 -1 -1 
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