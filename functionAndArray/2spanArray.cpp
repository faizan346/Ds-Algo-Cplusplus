#include<bits/stdc++.h>
using namespace std;

int spanArray(int *a, int n) {
    int min = INT_MAX;
    int max = INT_MIN;
    for(int i = 0; i < n; i++) {
        if(a[i] > max) {
            max = a[i];
        }
        if(a[i] < min) {
            min = a[i];
        }
    }
    return max - min;
}

int main() {
    int n;
    cin >> n;
    int a[n];
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    cout << spanArray(a, n) << endl;
    return 0;
}