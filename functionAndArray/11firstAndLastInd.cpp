#include<bits/stdc++.h>
using namespace std;

void firstAndLastInd(int *a, int l, int r, int k) {
    int ll = l, rl = r;
    int lf = l, rf = r;
    int last, first;
    while(ll <= rl) {
        int mid = ll + (rl - ll)/2;
        if(a[mid] == k) {
            last = mid;
            ll = mid + 1;
        } else if(a[mid] > k) {
            rl = mid - 1;
        } else {
            ll = mid + 1;
        }
    }
    while(lf <= rf) {
        int mid = lf + (rf - lf)/2;
        if(a[mid] == k) {
            first = mid;
            rf = mid - 1;
        } else if(a[mid] > k) {
            rf = mid - 1;
        } else {
            lf = mid + 1;
        }
    }
    cout << "first : " << first << endl;
    cout << "last : " << last << endl;
}

int main() {
    int n; 
    cin >> n;
    int a[n];
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int k;
    cin >> k;
    firstAndLastInd(a, 0, n-1, k);
    return 0;
}