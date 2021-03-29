#include<bits/stdc++.h>
using namespace std;

int maxInArray(int *a, int n, int i) {
    if(i == n - 1) {
        return a[i];
    }
    int m = maxInArray(a, n, i+1); //it gives the max in i+1 to n
    if(a[i] > m) {
        m = a[i];
    }
    return m;
}

int main() {
    int n;
    cin >> n;
    int a[n];
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    cout << maxInArray(a, n, 3) << endl;
    return 0;
}