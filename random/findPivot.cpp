#include <bits/stdc++.h>
using namespace std;

//pivot is smallest 
int findPivot(int *a, int l, int r) {
    while(l != r) { //we have to stop at l == r not going further becox that's our pivot element 
        int mid = l + (r-l)/2;
        if(a[mid] > a[r]) 
            l = mid+1; //serach right side of mid because mid is defnitely bigger than pivot,
        else 
            r = mid; //serach left includeing pivot because mid could be smallest.
    }
    return a[l]; //l==r==pivot.
}

int main () {
    int a[] = {20 ,30, 40, 50, 5, 10}; //original 5,10,20,30,40,50 but we rotate it  a little
    cout << findPivot(a,0, 5) << endl;
    return 0;
}