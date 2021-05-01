#include<bits/stdc++.h>
using namespace std;
// a > b
void diffOfTwoArrays(int *a, int *b, int n, int m) {
    int c = 0;
    int k = n;
    int s[k];
    while(n > 0) {
        int d1 = 0, d2 = 0;
        d1 = a[n-1];
        if(m > 0) {
            d2 = b[m-1];
        }
        d1 = d1 + c;
        int sub;
        if(d1 >= d2) {
            sub = d1 - d2;
            c = 0;
        } else {
            sub = d1 + 10 - d2;
            c = -1;
        }
        s[n-1] = sub%10;
        n--;
        m--;
    }
    int i;
    for(i = 0 ; i < k; i++) {
        if(s[i]) break;
    }
    for(; i < k; i++) {
        cout << s[i];
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
    diffOfTwoArrays(a, b, n , m);
    return 0;
}