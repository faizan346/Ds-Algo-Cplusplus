#include<bits/stdc++.h>
using namespace std;

void printBarChart(int *a, int n) {
    int max = INT_MIN;
    for(int i = 0; i < n; i++) {
        if(a[i] > max) {
            max = a[i];
        }
    }
    while(max) {
        for(int i = 0; i < n; i++) {
            if(a[i] - max >= 0) {
                cout << "* ";
            } else {
                cout << "  ";
            }
        }
        max--;
        cout << endl;
    }
}

int main() {
    int n;
    cin >> n;
    int a[n];
    for(int i=0;i<n;i++) {
        cin >> a[i];
    }
    printBarChart(a, n);
    return 0;
}