#include<bits/stdc++.h>
using namespace std;

void printCeilFloor(int *a, int l, int r, int k) {
    int mid;
    int n = r - l + 1;
    while(l <= r) {
        mid = l + (r-l)/2;
        if(a[mid] == k) break;
        else if(a[mid] > k) {
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    if(l >= r) {
        if(l < n) cout << "ceil : " << a[l] << " ";
        if(r > -1) cout << "floor : " << a[r];
        cout << endl;
    } else {
        cout << "floor = ceil = " << a[mid] << endl; 
    }
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
    printCeilFloor(a, 0, n-1, k);
    return 0;
}