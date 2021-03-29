#include <bits/stdc++.h>
using namespace std;

#define CLOCK_END cerr << "\nTime taken : " << (clock()-time_p) << " microSec\n";
#define CLOCK_START time_p = clock();

void countSortForRadix(int *a, int n, int exp) {
    int freqArray[10] = {0};
    for(int i = 0; i < n; i++) {
        freqArray[a[i]/exp % 10]++;
    }
    freqArray[0]--;
    //prefix summ array for index postion
    for(int i = 1; i< 10; i++) {
        freqArray[i] = freqArray[i] + freqArray[i-1];
    }
    int reva[n];
    for(int i = n-1; i > -1; i--) {
        reva[i] = a[n-1-i];
    }
    for(int i = 0; i < n; i++) {
        a[freqArray[reva[i]/exp % 10]] = reva[i];
        freqArray[reva[i]/exp % 10]--;
    }
}

void radixSort(int *a, int n) {
    if(n < 2) return;
    int max = INT_MIN;
    for(int i = 0; i < n; i++) {
        if(a[i] > max) max = a[i];
    }
    int exp = 1;
    while(max/exp) {
        countSortForRadix(a, n, exp);
        exp = exp*10;
    }
}


void countSort(int *a, int n) {
    if(n < 2) return;
    int min = INT_MAX;
    int max = INT_MIN;
    for(int i = 0; i < n; i++) {
        if(a[i] > max) {
            max = a[i];
        } 
        if(a[i] < min) {
            min = a[i];
        }
    }
    int sizeFreqArray = max - min + 1;
    int freqArray[sizeFreqArray];
    for(int i = 0; i < sizeFreqArray; i++) freqArray[i] = 0;

    for(int i = 0; i < n; i++) {
        freqArray[a[i]-min]++;
    }
    freqArray[0]--; 
    for(int i = 1; i < sizeFreqArray; i++) {
        freqArray[i] = freqArray[i] + freqArray[i-1];
    }
    int reva[n];
    for(int i = n-1; i > -1; i--) {
        reva[i] = a[n-1-i];
    }
    for(int i = 0; i < n; i++) {
        a[freqArray[reva[i] - min]] = reva[i];
        freqArray[reva[i] - min]--;
    }
}

void insertionSort(vector<float> &a) {
    int n = a.size();
    for(int i = 1; i < n; i++) {
        float temp = a[i];
        int j = i-1;
        while(j >= 0 && temp < a[j]) {
            a[j+1] = a[j];
            j--;
        }
       a[j+1] = temp;
    }
}

void bucketSort(float *a, int n) {
    vector<float> bucket[10];
    for(int i = 0; i < n; i++) {
        int ind = 10 * a[i];
        bucket[ind].push_back(a[i]);
        
    }
    //sorting bucket lists individually
    for(int i = 0; i < 10; i++) {
        insertionSort(bucket[i]);
    }
    int ind = 0;
    for(int i = 0; i < 10; i++) {
        for(auto el : bucket[i]) {
            a[ind] = el;
            ind++;
        }
    }
}

int main() {
    int n;

    int a[] = {171,210,131,341,316,246,351,121,112,218,324};
    n = 11;
    cout << "\nRadix Sort =>\n";
    radixSort(a, n);
    cout << "Sorted Array : ";
    for(int i = 0; i < n; i++) {
        cout << a[i] << " " ;
    }
    cout << endl;

    int b[] = {7,6,3,4,16,5,7,13,8,12,6,6};
    n = 12;
    cout << "\nCount Sort =>\n";
    countSort(b, n);
    cout << "Sorted Array : ";
    for(int i = 0; i < n; i++) {
        cout << b[i] << " " ;
    }
    cout << endl;

    float c[] = {0.71,0.10,0.31,0.41,0.16,0.46,0.51,0.21,0.12,0.08};
    n = 10;
    cout << "\nbucket Sort =>\n";
    bucketSort(c,n);
    cout << "Sorted Array : ";
    for(int i = 0; i < n; i++) {
        cout << c[i] << " " ;
    }
    cout << "\n\n";
    return 0;
}