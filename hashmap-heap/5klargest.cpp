#include<bits/stdc++.h>
using namespace std;


int main() {
    int n , k;
    cin >>n >> k;
    int a[n];
    for(int i = 0; i <n; i++) {
        cin >> a[i];
    }
    priority_queue<int, vector<int>, greater<int>> pq;
    for(int i = 0; i < n; i++) {
        if(pq.size() < 3) {
            pq.push(a[i]);
        } else {
            int top = pq.top();
            if(top < a[i]) {
                pq.pop();
                pq.push(a[i]);
            }
        }
    }
    for(int i = 0; i < k; i++) {
        cout << pq.top() << " ";
        pq.pop();
    }
    cout << endl;
    return 0;
}