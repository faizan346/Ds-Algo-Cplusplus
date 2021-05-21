#include<bits/stdc++.h>
using namespace std;


int main() {
    int n;
    cin >> n;
    int a[n];
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    //max profit upto nth stock from left side
    int mpls[n];
    mpls[0] = 0; 
    int leftMin = a[0]; // first stock is min for range n = 1
    for(int i = 1; i < n; i++) {
        leftMin = min(leftMin, a[i]);
        int profit = a[i] - leftMin;
        if(mpls[i-1] < profit) {
            mpls[i] = profit;
        } else {
            mpls[i] = mpls[i-1];
        }
    }
    //max profit upto nth stock from right side
    int mprs[n];
    mprs[n-1] = 0;
    int rightMax = a[n-1];
    for(int i = n-2; i >= 0; i--) {
        rightMax = max(rightMax, a[i]);
        int profit = rightMax - a[i];
        if(mprs[i+1] < profit) {
            mprs[i] = profit;
        } else {
            mprs[i] = mprs[i+1];
        }
    }
    int maxProfit = 0;
    for(int i = 0; i < n; i++) {
        int profit = mprs[i] + mpls[i];
        if(maxProfit < profit) {
            maxProfit = profit;
        }
    }
    cout << maxProfit << endl;
}