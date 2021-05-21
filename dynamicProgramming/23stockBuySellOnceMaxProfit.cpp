#include<bits/stdc++.h>
using namespace std;


int main() {
    int n;
    cin >> n;
    int a[n];
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int lastMin = a[0]; // first stock is min for range n = 1
    int maxProfit = 0; // buy and sell stock at same day
    for(int i = 1; i < n; i++) {
        lastMin = min(lastMin, a[i]);
        int profit = a[i] - lastMin;
        if(maxProfit < profit) {
            maxProfit = profit;
        }
    }
    cout << maxProfit << endl;
}