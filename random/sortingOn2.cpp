#include <bits/stdc++.h>
using namespace std;

#define CLOCK_END cerr << "\nTime taken : " << (clock()-time_p) << " microSec\n";
#define CLOCK_START time_p = clock();

void bubbleSort(int *a, int n) {
    for(int i = 0 ; i < n-1; i++) {
        bool flag = false;
        for(int j = 0 ; j < n-1-i; j++) {
            if(a[j] > a[j+1]) {
                 swap(a[j], a[j+1]);
                 flag = true;
            }
        }
        if(!flag) return;
    }
}

void selectionSort(int *a, int n) {
    for(int i = 0; i < n; i++) {
        int minInd = i;
        for(int j = i+1; j < n; j++) {
            if(a[minInd] > a[j]) {
                minInd = j;
            }
        }
        swap(a[i], a[minInd]);
    }
}

void insertionSort(int *a, int n) {
    for(int i = 1; i < n; i++) {
        int temp = a[i];
        int j = i-1;
        while(j >= 0 && a[j] > temp) {
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = temp;
    }
}

int main() {
    clock_t time_p;
    srand(time(0));
    int run = 10;
    while(run){
        int n = 100*run;
        int a[n], b[n], c[n];
        for(int i = 0; i<n; i++) {
           c[i] = b[i] = a[i] = rand();
        }

        cout << "bubble Sort :";
        CLOCK_START
        bubbleSort(a, n);
        CLOCK_END
        
        cout << "selection Sort :";
        CLOCK_START
        selectionSort(b, n);
        CLOCK_END

        cout << "insertion Sort :";
        CLOCK_START
        insertionSort(c, n);
        CLOCK_END

        cout << endl;
        run--;
    }
    return 0;
}