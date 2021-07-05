#include<bits/stdc++.h>
using namespace std;


int main() {
    int n;
    cin >> n;
    vector<int> a(n, 0);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int i = 0;
    int j = n-1;
    int ans = 0;
    while(i < j) {
        int width = j - i;
        if(a[i] < a[j]) { 
            // if a[i] is smaller than a[j] it is gaurantee that if 
            // we dec j the larger element the container we get would be smaller as 
            // width got smaller and min height remain same but if inc i than 
            //it could either inc or dec depends on next height.
            ans = max(ans, width*a[i]);
            i++;
        } else {
            ans = max(ans, width*a[j]);
            j--;
        }
    }
    cout << ans << endl;
    return 0;
}

// 9
// 1
// 8
// 6
// 2
// 5
// 4
// 8
// 3
// 7