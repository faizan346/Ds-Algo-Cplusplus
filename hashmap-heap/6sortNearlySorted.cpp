#include<bits/stdc++.h>
using namespace std;


int main() {
    int n, k;
    cin >> n >> k;
    int a[n];
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    priority_queue<int, vector<int>, greater<int>> pq;
    //push krdye maine k-1 element
    for(int j = 0; j < k-1; j++) {
            pq.push(a[j]);
    }
    //k-1 index se loop chalaay 
    //cuur element ko priority queu mai dala use lenght k hogai
    //aur uske k-1 peeche vala index pr min of prioirty que
    //save krlya array mai fir release krdya pq se. dubara k-1 element bachche
    for(int i = k-1; i < n; i++) {
        pq.push(a[i]);
        a[i-(k-1)] = pq.top();
        pq.pop();
    }
    //bche hue k-1 element ko bhi save krlya..
    for(int i = n-(k-1); i < n; i++) {
        a[i] = pq.top();
        pq.pop();
    }
    for(auto x : a) cout << x << " ";
    cout << endl;
    return 0;
}