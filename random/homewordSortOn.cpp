#include <bits/stdc++.h>
using namespace std;

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
    cout << "\nmaxNumber = " << max << endl;
    cout << "we apply count Sort to every digit from lsd to msd (DigitsInMaxNumber): 3"<< endl;
    int exp = 1;
    int digit = 1;
    while(max/exp) {
        countSortForRadix(a, n, exp);
        cout << "\nAfter sorting according to least significant digit : " << digit << endl;
        for(int i = 0; i < n ; i++) {
            cout << a[i] << " ";
        }
        digit++;
        cout << endl;
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
    cout << "\nminNumber = " << min << "  maxNumber = " << max << endl;
    int sizeFreqArray = max - min + 1;
     cout << "Size of freqArray(maxNumber - minNumber + 1) = " << sizeFreqArray << endl;
    int freqArray[sizeFreqArray];
    for(int i = 0; i < sizeFreqArray; i++) freqArray[i] = 0;
    for(int i = 0; i < n; i++) {
        freqArray[a[i]-min]++;
    }
    cout <<"frequency of each element => " << endl;
    for(int i = 0; i < sizeFreqArray; i++) {
        cout << "freqArray["<< i << "]("<< i + min<<") : " << freqArray[i] << endl; 
    }
    freqArray[0]--; //for proper indexing
    for(int i = 1; i < sizeFreqArray; i++) {
        freqArray[i] = freqArray[i] + freqArray[i-1];
    }
    cout <<"prefix sum of frequency to get index => " << endl;
    for(int i = 0; i < sizeFreqArray; i++) {
        cout << "freqArray["<< i << "]("<< i + min<<") : " << freqArray[i] << endl; 
    }
    int reva[n];
    for(int i = n-1; i > -1; i--) {
        reva[i] = a[n-1-i];
    }
    cout << "\niterate array from end and fill the element according to prefix array = >" << endl;
    for(int i = 0; i < n; i++) {
        cout << "i = " << n-1-i << " ,a[i] = " << reva[i] << " ,freqArrayInd = " << reva[i] - min << endl;
        cout << "freqArray[" << reva[i] - min <<"] = " << freqArray[reva[i] - min] << endl;
        a[freqArray[reva[i] - min]] = reva[i];
        cout << "after : ";
         for(int j = 0; j < n; j++) cout << a[j] << " ";
         cout << endl;
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
    cout << "\nafter inserting elements in bucket =>\n";
     for(int i = 0; i < 10; i++) {
            cout << "bucket[" << i << "] : ";
            for(auto el : bucket[i]) {
                cout << el << " " ;
            }
            cout << endl;
        }
    //sorting bucket lists individually
    for(int i = 0; i < 10; i++) {
        insertionSort(bucket[i]);
    }
    cout << "\nafter sorting individual bucket =>\n";
     for(int i = 0; i < 10; i++) {
            cout << "bucket[" << i << "] : ";
            for(auto el : bucket[i]) {
                cout << el << " " ;
            }
            cout << endl;
        }
    int ind = 0;
    for(int i = 0; i < 10; i++) {
        for(auto el : bucket[i]) {
            a[ind] = el;
            ind++;
        }
    }
    cout << "\nafter iterating all bucket's lists in order =>\n";
}

int main() {
    int n;

    int b[] = {1,0,2,2,1,0,1,1,5,6,7,5,4,2,2,0,0,1};
    n = 12;
    cout << "\nCount Sort =>\n";
      cout << "unSorted Array : ";
    for(auto x : b) cout << x << " ";
    countSort(b, n);
    cout << "Sorted Array : ";
    for(int i = 0; i < n; i++) {
        cout << b[i] << " " ;
    }
    cout << endl;

    int a[] = {171,210,131,341,316,246,351,121,112,218,324};
    n = 11;
    cout << "\nRadix Sort =>\n";
      cout << "unSorted Array : ";
    for(auto x : a) cout << x << " ";
    radixSort(a, n);
    cout << "\nSorted Array : ";
    for(int i = 0; i < n; i++) {
        cout << a[i] << " " ;
    }
    cout << endl;

    float c[] = {0.71,0.10,0.31,0.41,0.16,0.46,0.51,0.21,0.12,0.08};
    n = 10;
    cout << "\nbucket Sort =>\n";
    cout << "unSorted Array : ";
    for(auto x : c) cout << x << " ";
    cout << endl;
    bucketSort(c,n);
    cout << "Sorted Array : ";
    for(int i = 0; i < n; i++) {
        cout << c[i] << " " ;
    }
    cout << "\n\n";
    return 0;
}