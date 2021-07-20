#include<bits/stdc++.h>
using namespace std;

int solve() {
    int n; 
    cin >> n;
    bool sub = false;
    int rem = n%4;
    if(rem > 2) {
        n += 4-rem;
        // if centinal year and not multiple of 400 than we sub to reach closest
        // leap year otherwise we will add to reach closest leap year
        sub = true; 
    } else {
        n -= rem;
    }
    if(n % 100 == 0) {
        if(n % 400 == 0) return n;
        else return (sub == true) ? n - 4 : n + 4;
    } else { // if(n % 4 == 0)
        return n;
    }
}

int main() {
    int tc = 1;
    cin >> tc;
    while(tc--) {
        cout << solve() << endl;
    }
    return 0;
}