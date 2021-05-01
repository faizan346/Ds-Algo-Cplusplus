#include<bits/stdc++.h>
using namespace std;

void display(int *a, int n) {
    for(int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
}

void reverse(int *a, int n) {
    // for(int i = 0; i < n/2; i++) {
    //     swap(a[i], a[n-1-i]);
    // }
    int i = 0; 
    int j = n-1;
    while (i < j) {
        int t = a[i];
        a[i] = a[j];
        a[j] = t;
        i++;
        j--;
    }
}

int main() {
    int n;
    cin >> n;
    int a[n];
    for(int i =0; i < n; i++) {
        cin >> a[i];
    }
    reverse(a, n);
    display(a, n);
    return 0;
}