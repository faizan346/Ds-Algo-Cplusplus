#include<bits/stdc++.h>
using namespace std;

// bs bs bs only one transaction allowed at a time
// bbss overlapping transaction not allowed
// so we just include all upstroke to get the max profit rather than selling it 
// to the next max stock as we would miss all the upstrokes in between
// which is much greater than just taking diff of max stock from curr stock
int main() {
    int n;
    cin >> n;
    int a[n];
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int profit = 0;
    int b = 0;
    int s = 0;
    for(int i = 0; i < n-1; i++) {
        if(a[i + 1] >= a[i]) {
            s++;
        } else {
            profit += a[s] - a[b];
            s = b = i + 1;
        }
    }
    profit += a[s] - a[b];
    cout << profit << endl;
}