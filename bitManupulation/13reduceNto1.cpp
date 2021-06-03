#include<bits/stdc++.h>
using namespace std;

void solve1(long long n) {
    int count = 0;
    while(n > 1) {
        if(n % 2 == 0) {
            n = n/2;
        } else {
            if(n < 4) {
                n--;
            } else if((n & 3) == 1) { // n % 4 == 1
                n--;
            } else if((n & 3) == 3) { // n % 4 == 3
                n++;
            } 
        }
        count++;
    }
    cout << count << endl;
}

int main() {
    long long n;
    cin >> n;
    solve1(n);
    return 0;
}