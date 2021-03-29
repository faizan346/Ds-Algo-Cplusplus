#include <bits/stdc++.h>
using namespace std;

#define CLOCK_END cerr << "\nTime taken : " << (clock()-time_p) << " microSec\n";
#define CLOCK_START time_p = clock();

void merge(int *a, int ll, int lr, int rl, int rr) {
    int start = ll, end = rr;
    int sizeMergedArray = end - start +1;
    int mergedArray[sizeMergedArray];
    int i = 0;
    while(ll <= lr && rl <= rr) {
        if(a[ll] <= a[rl]) {
            mergedArray[i] = a[ll];
            ll++;
        } else {
            mergedArray[i] = a[rl];
            rl++;
        }
        i++;
    }
    while(ll <= lr) {
        mergedArray[i] = a[ll];
        ll++;
        i++;
    }
    while(rl <= rr) {
        mergedArray[i] = a[rl];
        rl++;
        i++;
    }
    i = 0;
    while(start <= end) {
        a[start] = mergedArray[i];
        start++;
        i++;
    }
}

void mergeSort(int *a, int l, int r) {
    if(l >= r) return;
    int mid = l + (r-l)/2;
    mergeSort(a, l, mid);
    mergeSort(a, mid+1, r);
    merge(a, l, mid, mid+1, r);
}

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
    for(int i = n-1; i > 0; i--) {
        swap(a[0], a[i]);       //deleting first element.
        heapify(a, i, 0);
    }
}

int main() {
    clock_t time_p;
    srand(time(0));
    int run = 10;
    while(run){
        int n = 10000*run;
        int a[n], b[n], c[n];
        for(int i = 0; i<n; i++) {
           c[i] = b[i] = a[i] = rand();
        }

        cout << "Merge Sort :";
        CLOCK_START
        mergeSort(a, 0, n-1);
        CLOCK_END
      
        cout << "Quick Sort :";
        CLOCK_START
        quickSort(b, 0, n-1);
        CLOCK_END

        cout << "Heap Sort :";
        CLOCK_START
        heapSort(c, n);
        CLOCK_END

        cout << endl;
        run--;
    }
    return 0;
}