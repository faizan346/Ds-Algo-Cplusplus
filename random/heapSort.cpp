#include <bits/stdc++.h>
using namespace std;

void heapify(int *a, int n, int i) {
    int leftChild = 2 * i + 1;
    int rightChild = 2 * i + 2;
    int largestInd = i;
    if(leftChild < n && a[largestInd] < a[leftChild]) {
        largestInd = leftChild;
    }
    if(rightChild < n && a[largestInd] < a[rightChild]) {
        largestInd = rightChild;
    }
    if(largestInd != i) {
        swap(a[largestInd], a[i]);
        heapify(a, n, largestInd);
    }
}

void heapSort(int *a, int n) {
    //create max heap
    for(int i = n/2 -1; i >= 0; i--) {
        heapify(a, n, i);
    }
    //delete max until heap gets empty.
    //and we do this for n-1 element as last element is already placed
    for(int i = n-1; i > 0; i--) {
        swap(a[0], a[i]);       //deleting first element.
        heapify(a, i, 0);
    }
}

int main() {
    clock_t time_p;
    int n = 10;
    int c[] = {71,10,31,41,16,46,51,21,13,8};
    cout << "\nHeap Sort ==>";
    cout << "\nUnsorted Array : ";
    for(int i = 0; i < n; i ++) {
        cout << c[i] << " ";
    }
    heapSort(c, n);
    cout << "\nSorted Array : ";
    for(int i = 0; i < n; i ++) {
        cout << c[i] << " ";
    }
    cout << "\n\n";
    return 0;
}