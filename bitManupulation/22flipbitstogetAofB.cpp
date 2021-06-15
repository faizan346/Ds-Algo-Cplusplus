#include<bits/stdc++.h>
using namespace std;


int main() {
    int a, b;
    cin >> a >> b;
    int x = a ^ b;
    int flip = 0;
    while(x) {
        x = x & (x-1);
        flip++;
    }
    cout << flip << endl;
    return 0;
}