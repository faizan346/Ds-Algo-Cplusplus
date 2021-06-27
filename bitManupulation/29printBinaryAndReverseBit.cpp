#include<bits/stdc++.h>
using namespace std;

string toBit(int n) {
    string s = "";
    while(n) {
        int dig = n % 2;
        n /= 2;
        s = (char)(dig + '0') + s; 
    }
    return s;
}

int toInt(string s) {
    int num = 0;
    int dig = 1;
    for(int i = s.size() - 1; i >= 0; i--) {
        char c = s[i];
        int d = s[i] - '0';
        num += d * dig;
        dig = dig * 2;
    }
    return num;
}

int main() {
    int n;
    cin >> n;
    int rev = 0;
    bool flag = false;
    int j = 0;
    for(int i = 31; i >= 0; i--) {
        if(flag) { // after encountering first one
            if(((1 << i) & n) != 0) {
                cout << 1;
                int mask = 1 << j;
                rev = rev | mask;
            } else {
                cout << 0;
            }
            j++;
        } else {
            if(((1 << i) & n) != 0) { // when first one encountered
                flag = true;
                cout << 1;
                int mask = 1 << j; // mask for rev index
                rev = rev | mask; // switch on the bits for rev num at rev ind.
                j++; // inc index of rev num
            }
        }
    }
    cout << endl;
    cout << rev << endl;
    return 0;
}