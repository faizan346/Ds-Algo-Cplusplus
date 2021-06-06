#include<bits/stdc++.h>
using namespace std;
//contiguous elements subarray means that an subarray should contain permutaion of 
// continous elements of lenth j-i+1 eg 5 2 3 1 4
int main() {
    int n;
    cin >> n;
    vector<int> a(n, 0);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int lon = 1;
    for(int i = 0; i < n - 1; i++) { 
        int minVal = a[i];
        int maxVal = a[i];
        unordered_set<int> set;
        set.insert(a[i]);
        for(int j = i+1; j < n; j++) {
            if(set.count(a[j])) { // if 6 8 8 9 comes it will pass without this
                break;
            }
            set.insert(a[j]);
            minVal = min(minVal, a[j]);
            maxVal = max(maxVal, a[j]);
            if(maxVal - minVal == j - i) {
                lon = max(lon, j - i + 1);
            }
        }
    }
    cout << lon << endl;
    return 0;
}