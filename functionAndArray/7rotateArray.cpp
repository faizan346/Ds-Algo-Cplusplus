#include<bits/stdc++.h>
using namespace std;

void display(int *a, int n) {
    for(int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
}
//with O(n) space complex
void rotateSpaceN(int *a, int n, int k) {
    // if k is multiple of n we get same value so we find remainder to rotate
    k = k%n;
    //if k is negative we can get same value k + n which is positive, give same rotaion index
    if(k < 0) k = k + n;

    int b[n]; //here we take extra space.
    for(int i = 0; i < n; i++) {
        b[(i+k)%n] = a[i];
    }
    for(int i = 0; i < n; i++) {
        a[i] = b[i];
    }
}

void reverse(int *a, int i, int j) {
    while(i < j) {
        int t = a[i];
        a[i] = a[j];
        a[j] = t;
        i++;
        j--;
    }
}

void rotate(int *a, int n, int k) {
    k = k%n;
    if(k < 0) k = k + n;
    k = n - k; // right side se rotate marna pdta hai
    reverse(a, 0, k-1);
    reverse(a, k, n-1);
    reverse(a, 0, n-1);
}

int main() {
    int n, k;
    cin >> n >> k;
    int a[n];
    for(int i =0; i < n; i++) {
        cin >> a[i];
    }
    rotate(a, n, k);
    display(a, n);
    return 0;
}