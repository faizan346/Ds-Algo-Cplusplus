#include<bits/stdc++.h>
using namespace std;
//pop, print, push
void slidingWindow(int *a, int n, int k) {
    stack<int> s;
    int nge[n];
    int maxArrayWindow[n-k+1];
    for(int i = n-1; i > -1; i--) { //iterate left to right
        //stack not empty and curr element will remove all non nge element
        while(!s.empty() && a[i] >= a[s.top()]) { 
            s.pop();
        }
        if(s.empty()) { //it means it has no nge 
            nge[i] = n; //setting it outside window for any last window possible
        } else { //the nge is at top of stack after removing all non nge
            nge[i] = s.top();
        }
        s.push(i); // push curr because it could be nge for othre element
    }
    int j = 0;
    for(int i = 0 ; i < n-k+1 ; i++) {
        if(j < i) j = i; //lags behind when the first element has no nge inside window so we set new j start from i
        while(nge[j] < k+i) { //next nge index not out of window
            j = nge[j]; // jump to next nge
        }
        maxArrayWindow[i] = a[j];
    }
    for(int x : maxArrayWindow) cout << x << " " ;
    cout << endl;
}


int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
#endif
    int n, k;
    cin >> n >> k;
    int a[n];
    for(int i = 0; i < n; i ++) {
        cin >> a[i];
    }
    slidingWindow(a, n, k);
    return 0;
}