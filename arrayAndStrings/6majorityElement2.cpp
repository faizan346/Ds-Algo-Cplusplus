#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n, 0);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<int> ans;
    // by observation i see that not more than two values are possible for ans.
    int val1 = a[0], val2 = a[0]; 
    int count1 = 1, count2 = 0;
    for(int i = 1; i < n; i++) {
        // wont effect count1 or count2 as these two val1 and val2 are top 2 fre values.
        // =============
        if(a[i] == val1) {
            count1++;
        } else if(a[i] == val2) {
            count2++; 
        // ==============
        } else { // distinct value not equal to val1 and val2 than we decrease counts
            count1--, count2--;
        }
        // it means distinct element are more which lead to count <= n/3 so we change val
        // start counting again from curr ith pos but one of count1 or count2 remain same.
        if(count1 <= 0 || count2 <= 0) { 
            if(count1 < count2) {
                val1 = a[i];
                count1 = 1;
                count2++;
            } else {
                val2 = a[i];
                count2 = 1;
                count1++;
            }
        }
    }
    int k = n/3;
    count1 = count2 = 0;
    for(auto x : a) {
        if(x == val1) count1++;
        if(x == val2) count2++;
    }
    cout << "[";
    if(count1 > k) ans.push_back(val1);
    if(count2 > k) ans.push_back(val2);
    for(int i = 0; i < ans.size(); i++) {
        cout << ans[i];
        if(i != ans.size()-1) cout << ", ";
    }
    cout << "]" << endl;
    return 0;
}