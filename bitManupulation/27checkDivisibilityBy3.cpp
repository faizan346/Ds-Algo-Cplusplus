#include<bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;
    int n = s.size();
    int odd = 0;
    int even = 0;
    for(int i = n-1; i >= 0; i--) {
        int dig = s[i] - '0';
        if(i % 2 == 0) {
            even += dig;
        } else {
            odd += dig;
        }
    }
    int diff = even - odd;
    if(diff % 3 == 0) {
        cout << "true";
    } else {
        cout << "false";
    }
    cout << endl;
    return 0;
}