#include<bits/stdc++.h>
using namespace std;
//pop, print, push
void nextGreaterElement(int *a, int n) {
    stack<int> s;
    int nge[n];
    for(int i = n-1; i > -1; i--) { //iterate left to right
        //stack not empty and curr element will remove all non nge element
        while(!s.empty() && a[i] >= s.top()) { 
            s.pop();
        }
        if(s.empty()) { //it means it has no nge 
            nge[i] = -1;
        } else { //the nge is at top of stack after removing all non nge
            nge[i] = s.top();
        }
        s.push(a[i]); // push curr because it could be nge for othre element
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