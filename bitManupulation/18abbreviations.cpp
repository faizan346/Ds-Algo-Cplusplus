#include<bits/stdc++.h>
using namespace std;

void abbreviations(string s) {
    int n = s.size();
    for(int i = 0; i < (1<<n); i++) {
        int count = 0;
        for(int j = 0; j < n; j++) {
            if(((1 << (n-j-1)) & i) != 0) {
                count++;
            } else {
                if(count > 0) {
                    cout << count;
                    count = 0;
                }
                cout << s[j];
            }
        }
        if(count > 0) cout << count;
        cout << endl;
    }
}

int main() {
    string s;
    cin >> s;
    abbreviations(s);
    return 0;
}