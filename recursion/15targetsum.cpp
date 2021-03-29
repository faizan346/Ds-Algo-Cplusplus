#include<bits/stdc++.h>
using namespace std;

void printTargetSumSubSet(int a[], int n, int sum, vector<int> set) {
    if(sum == 0) {
        for(auto it = set.rbegin(); it != set.rend(); it++) {
            cout << *it << " ";
        }   
        cout << endl;
        return;
    }
    if(n == 0) {//backtracking 
        return;
    }
    printTargetSumSubSet(a, n-1, sum, set);
    if(a[n-1] <= sum) {
        set.push_back(a[n-1]);
        printTargetSumSubSet(a, n-1, sum - a[n-1], set);
    }
}

int main() {
    int n, sum;
    cin >> n >> sum;
    int a[n];
    for(int i =0 ; i < n; i++) {
        cin >> a[i];
    }
    vector<int> set;
    printTargetSumSubSet(a, n, sum, set);
    return 0;
}