#include<bits/stdc++.h>
using namespace std;

int longestBitonicSubSeq(vector<int>& a) {
    int n = a.size();
    int dpl[n]; 
    dpl[0] = 1;
    for(int i = 1; i < n+1; i++) {
        dpl[i] = 1; 
        for(int j = 0; j < i; j++) {
            if(a[i] >= a[j]) { 
                dpl[i] = max(dpl[i], dpl[j] + 1);
            }
        }
    }
    //decreasing subsequence or increasing from right
    int dpr[n]; 
    dpr[n-1] = 1;
    for(int i = n-2; i >= 0; i--) {
        dpr[i] = 1; 
        for(int j = i+1; j < n; j++) {
            if(a[i] >= a[j]) { 
                dpr[i] = max(dpr[i], dpr[j] + 1);
            }
        }
    }
    int longestBitonic = INT_MIN;
    for(int i = 0; i < n; i++) {
        int bitonic = dpr[i] + dpl[i] - 1; // minus as both contain critical point.
        if(longestBitonic < bitonic) longestBitonic = bitonic;
    }
    return longestBitonic;
}
// 10
// 10 22 9 33 21 50 41 60 80 1

int main () {
    int n;
    cin >> n;
    vector<int> a;
    for(int i = 0; i < n; i++) {
        int v;
        cin >> v;
        a.push_back(v);
    }
    cout << longestBitonicSubSeq(a) << endl;
}