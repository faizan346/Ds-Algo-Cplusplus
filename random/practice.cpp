#include <bits/stdc++.h>
using namespace std;

void printSubSet(char *a, int n, string s) {
   if(n == 0) {
       cout << s << endl;
       return;
   }
   printSubSet(a, n-1, s);   //print subset of n-1 length strength when i didn't consider this number
   printSubSet(a, n-1, a[n-1]+s); // when i consider this number.
}

int main() {
    int n;
    cin >> n;
    char a[n];
    string s = "";
    for(int i = 0; i<n; i++) {
        cin >> a[i];
    }
    printSubSet(a,n, s);
}