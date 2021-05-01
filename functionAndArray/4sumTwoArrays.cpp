#include<bits/stdc++.h>
using namespace std;

void sumOfTwoArrays(int *a, int *b, int n, int m) {
    int c = 0;
    int s[max(n, m) + 1];
    int i = 0;
    while(n > 0 || m > 0 || c > 0) {
        int d1 = 0, d2 = 0;
        if(n > 0) {
            d1 = a[n-1];
        }
        if(m > 0) {
            d2 = b[m-1];
        }
        int sum = d1 + d2 + c;
        s[i] = sum%10;
        c = sum/10;
        n--;
        m--;
        i++;
    }
    i--;
    while(i >= 0) {
        cout << s[i];
        i--;
    }
    cout << endl;
}

int main() {
    int n, m;
    cin >> n >> m;
    int a[n], b[m];
    for(int i =0; i < n; i++) {
        cin >> a[i];
    }
    for(int i = 0; i < m; i++) {
        cin >> b[i];
    }
    sumOfTwoArrays(a, b, n , m);
    return 0;
}