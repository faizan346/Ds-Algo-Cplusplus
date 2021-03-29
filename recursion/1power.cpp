#include<bits/stdc++.h>
using namespace std;

int power(int x, int n) {// expectation to get x power n
    if(n == 0) {
        return 1;
    }
    int xnHalf = power(x, n/2); //faith xnHalf will give power x^N/2 
    int xn = xnHalf * xnHalf; // xn will be found through faith outputs
    if(n%2 != 0) {
        xn = xn * x; // if n is ood we need to multily one more to get xn
    }
    return xn;
}

int main() {
    cout << power(2, 5) << endl; 
    return 0;
}