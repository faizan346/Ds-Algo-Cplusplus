#include<bits/stdc++.h>
using namespace std;


int main() {
    int n;
    cin >> n;
    int counter = 0;
    while(n != 0) {
        int rsbm = n & -n;
        n = n - rsbm;
        counter++;
    }
    cout << counter << endl;
    return 0;
}