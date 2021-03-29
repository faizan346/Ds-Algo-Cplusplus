#include<bits/stdc++.h>
using namespace std;
//pop, print, push
//we use index in to store nge it will help in span calculation
void span(int *a, int n) {
    stack<int> s;
    int span[n];
    for(int i = 0; i < n; i ++) { //iterate right to left for ngel
        //stack not empty and curr element will remove all non nge element
        while(!s.empty() && a[i] >= a[s.top()]) { 
            s.pop();
        }
        if(s.empty()) { //it means it has no nge 
            span[i] = i + 1;
        } else { //the nge is at top of stack after removing all non nge
            span[i] = i - s.top();
        }
        s.push(i); // push curr because it could be nge for othre element
    }
    for(int x : span) cout << x << " ";
    cout << endl;
}

//9
//2 5 9 3 1 12 6 8 7
// 1 2 3 1 1 6 1 2 1 
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
    span(a, n);
    return 0;
}