#include<bits/stdc++.h>
using namespace std;


int main() {
    int n;
    cin >> n;
    char a[n];
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int totalSet = 1 << n;
    for(int i = 0; i < totalSet; i++) {
        string set = "";
        int k = i;
        for(int j = n-1; j >= 0; j--) {
            if(k%2 == 0) {
                set = "- " + set;
            }
            if(k%2 == 1) {
                set = " " + set;
                set = a[j] + set;
            }
            k = k/2;
        }
        cout << set << endl;
    }

    return 0;
}