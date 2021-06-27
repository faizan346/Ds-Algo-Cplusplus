#include<bits/stdc++.h>
using namespace std;


int main() {
    int n;
    cin >> n;
    vector<int> a(n, 0);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    vector<string> ans;
    int minXor = INT_MAX;
    // if a <= b <= c than we can say for sure that a^b or b^c  <= a^c 
    // why ?? there is giong to be first bit where 'a' and 'c' differ 
    // at that bit b can either be 0 or 1 so if it is 0 than xor of b with a 
    // would be min and if it is 1 than xor of b with a give us min as that
    // would make that bit 0. Any other number greater than c would bring the diff
    // earlier for bit of a and that would make bigger xors . that why we sort
    // and check only adjacent pairs. 
    for(int i = 0; i < n-1; i++) {
        int x = a[i] ^ a[i+1];
        if(x < minXor) {
            minXor = x;
            ans = vector<string>();
            ans.push_back(to_string(a[i]) + ", " + to_string(a[i+1]));
        } else if(x == minXor) {
            ans.push_back(to_string(a[i]) + ", " + to_string(a[i+1]));
        }
    }
    for(auto x : ans) {
        cout << x << endl;
    }
    return 0;
}