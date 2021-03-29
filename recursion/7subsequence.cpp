#include <bits/stdc++.h>
using namespace std;

//it is collecting answers when returning the calls
vector<string> subSequence(char *a, int n) {
    if(n == 0) {
        vector<string> ns;
        ns.push_back("");
        return ns;
    }
    vector<string> s = subSequence(a, n-1);
    vector<string> ns;
    for(auto x : s) {
        ns.push_back(x + "");
    }
    for(auto x : s) {
        ns.push_back(x + a[n-1]);
    }
    return ns;
}

//it is printing answers on the base case and on returning it just releases memory.hence it doesn't collect answer
void printSubSet(char *a, int n, string s) {
   if(n == 0) {
       cout << s << endl;
       return;
   }
   printSubSet(a, n-1, s);   //print subset of n-1 length strength when i didn't consider this number
   printSubSet(a, n-1, a[n-1] + s); // when i consider this number.
   //i m just strong data in each stack node in euler's path and printing data of last end node.
}

int main() {
    int n;
    cin >> n;
    char a[n];
    for(int i = 0; i<n; i++) {
        cin >> a[i];
    }
    vector<string> s = subSequence(a,n);
    for(auto x : s) {
        cout << x << endl;
    }
}