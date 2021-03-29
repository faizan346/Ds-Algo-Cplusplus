#include<bits/stdc++.h>
using namespace std;

int randomPivot(int l, int r) {
    srand(time(0));
    int size = r - l + 1;
    int pivot = rand()%size + l;
    return pivot;
}

int randomPartition(int *a, int l, int r) {
    int pivot = randomPivot(l, r); 
    swap(a[pivot], a[r]);  
    pivot = r;
    int partitionInd = l;
    while(l < r) {
        if(a[pivot] >= a[l]) {
            swap(a[partitionInd], a[l]);
            partitionInd++;
        }
        l++;
    }
    swap(a[partitionInd], a[pivot]);
    return partitionInd;
}
int quickSelect(int *a, int l , int r, int k) {
    if(l > r) return INT_MIN;
    int partitionInd = randomPartition(a, l, r);
    if(k == partitionInd) return a[k];
    if(k < partitionInd) return quickSelect(a, l, partitionInd - 1, k);
    else return quickSelect(a,partitionInd + 1, r, k);
}

int main() {
    int a[] = {3,1,6,4};
    int n = sizeof(a)/sizeof(a[0]);
    cout << quickSelect(a,0, n-1, 3) << endl;
    return 0;
}