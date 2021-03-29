#include<bits/stdc++.h>
using namespace std;

#define CLOCK_END cerr << "\nTime taken : " << (clock()-time_p) << " ns\n";
#define CLOCK_START time_p = clock();

bool linearSearch(int *a, int valueToSearch) {
    for(int i = 0; i < 100000; i++) {
        if(a[i] == valueToSearch) return true;
    }
    return false;
}

bool binarySearch(int *a, int valueToSearch, int l, int r) {
    while(l <= r) {
        int mid = l + (r-l)/2;
        if(a[mid] == valueToSearch) return true;
        if(a[mid] < valueToSearch) {
            l = mid + 1;
        }
        else {
            r = mid - 1;
        }
    }
    return false;
}

int main() {
    clock_t time_p;
    int a[1000000];
    for(int i = 0 ; i < 100000 ; i++) {
        a[i] = i;
    }
    int n[10] = {40000, 45000, 50000, 55000, 60000, 65000, 
        70000, 75000, 80000, 85000};
    int i = 10;
    while(i--) {
        cout<< "linear Search :";
        CLOCK_START
        linearSearch(a, n[i]);
        CLOCK_END

        cout<< "binary Search :";
        CLOCK_START
        binarySearch(a, n[i], 0, 99999);
        CLOCK_END
        
        cout << endl;
    }
    return 0;
}