#include<bits/stdc++.h>
using namespace std;

int main() {
    
    int a[] = {3,4,-10, 7,0,9,10,-50,10,5,5};
    int n = sizeof(a)/sizeof(a[0]);
    int max = INT_MIN;
    int currSum = 0;
    for(int i = 0; i < n; i ++) {
        if(currSum + a[i] < 0) {
            currSum = 0;
            continue;
        }
        currSum += a[i];
        if(max < currSum) {
            max = currSum;
        }
    }
    cout << max << endl;
    return 0;
}