#include <bits/stdc++.h>
using namespace std;

int partition(int *a, int l, int r) {
    int pivot = r;
    int partitionIndex = l;
    while(l < r) {
        if(a[l] <= a[pivot]){
            swap(a[l], a[partitionIndex]);
            partitionIndex++;
        }
        l++;
    }
    swap(a[pivot], a[partitionIndex]);
    return partitionIndex;
}

void quickSort(int *a, int l, int r) {
    if(l >= r) return;
    int partitionIndex = partition(a, l, r);
    quickSort(a, l, partitionIndex-1);
    quickSort(a, partitionIndex+1, r);
}

int main() {
    int n = 12;
    int c[] = {38, 81, 22, 48, 13, 69, 93, 14, 45, 58, 79, 72};
    cout << "\nQuick Sort ==>";
    cout << "\nUnsorted Array : ";
    for(int i = 0; i < n; i ++) {
        cout << c[i] << " ";
    }
    quickSort(c, 0, n-1);
    cout << "\nSorted Array : ";
    for(int i = 0; i < n; i ++) {
        cout << c[i] << " ";
    }
    cout << "\n\n";
    return 0;
}