#include<bits/stdc++.h>
using namespace std;
//normal way to find whether number is power of 2.
bool isPowerTwo(int x) {
    if(x == 0) 
        return false;
    else {
        while(x%2 == 0) x /= 2;
        return (x == 1);
    }
}
//using bits 
bool isPowerTwoBits(int x) {
    //(x&(x-1)) in x-1 chagne rightmost set bit to end bit into opposite bits.
    // and with & opp with x give zero for all those right bits starting with righmost set bit.
    return (x && !(x&(x-1)));
}
//counting number of ones in bits representation of a number.
// logN in general if we divide by 2 to find nubmer of ones.
// using bits logic can find in k time where k is length of bits of number
int numberOfOnes(int x) {
    int count = 0;
    while(x) {
        x = x&(x-1);
        count++;
    }
    return count;
}
// checking whether ith bit set in a number.
bool isBitSet(int x, int i) {
    return x&(1<<i);
}
void generateSubsets(char a[], int n) {
    for(int i = 0; i < (1<<n); i++) {
        for(int j = 0; j < n; j++) {
            if(i & (1<<j)) cout << a[j] << " ";
        }
        cout << endl;
    }
}
//using recursion
// void subsets(char a[], int n, char b[]) {
//     if(n == 0) {
//         for(int i = 4; i >= 0; i--) {
//             if(b[i] != '0') cout << b[i] << " ";
//         }
//         cout << endl;
//         return;
//     }
//     b[n-1] = a[n-1];
//     subsets(a, n-1, b);
//     b[n-1] = '0';
//     subsets(a, n-1, b);
// }
//above one is unnecessary.
void printSubSet(char *a, int n, string s) {
   if(n == 0) {
       cout << s << endl;
       return;
   }
   printSubSet(a, n-1, s);
   printSubSet(a, n-1, s+a[n-1]);
}
//largest power of 2 for given number n
int largestPowerOftwo(int n) {
    //making all bits to the right of msb to 1. 
    //for 16 bit , we can do more 
    n = n | n>>1;
    n = n | n>>2;
    n = n | n>>4;
    n = n | n>>8;
    // n = x + (x-1) = 2*x - 1;  wher x is of power of 2
    return (n+1)>>1;
}
int main() {
    int n = 5;
    char a[] = {'a','b','c','d','e'};
    char b[n];
    //cout << isPowerTwoBits(4) << isPowerTwoBits(6);
    //cout << numberOfOnes(6);
    //cout << isBitSet(5,0) << isBitSet(5,1)<<isBitSet(5,2);
    //generateSubsets(a, n);
    //subsets(a, n, b);
    //cout << largestPowerOftwo(7);
    cout << endl;
}

// 1 << n = 2^n
// 4 >> 1 = 4/2^1
// 6 >> 1 = 3
// 5 >> 1 = 2
// x ^ ( x & (x-1)) : Returns the rightmost 1 in binary representation of x.
// x & (-x) : Returns the rightmost 1 in binary representation of x
// x | (1 << n) : Returns the number x with the nth bit set.
