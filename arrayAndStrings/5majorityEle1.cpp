#include<bits/stdc++.h>
using namespace std;


int main() {
    int n;
    cin >> n;
    vector<int> a(n, 0);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int maj = a[0];
    int count = 1;
    for(int i = 1; i < n; i++) {
        if(maj != a[i]) {
            count--;
            if(count == 0) {
                maj = a[i];
                count = 1;
            }
        } else {
            count++;
        }
    }
    count = 0;
    for(auto x : a) {
        if(x == maj) count++;
    }
    if(count > n/2) cout << maj;
    else cout << "No Majority Element exist";
    cout << endl;
    return 0;
} 