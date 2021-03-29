#include<bits/stdc++.h>
using namespace std;

bool compare(pair<int,int> a, pair<int,int> b) {
    return a < b;
}

void mergeInterval() {
    int n;
    cin >> n;
    pair<int, int> p[n];
    for(int i= 0; i < n; i ++) {
        cin >> p[i].first >> p[i].second;
    }
    sort(p, p+n, compare);
    stack<pair<int, int>> s;
    s.push(p[0]);
    for(int i = 1; i < n; i ++) {
        pair<int, int> a = s.top();
        if(a.second >= p[i].first) { // agar next pair number ka frist digit bda hota to mai push krta direct
            if(a.second < p[i].second) { //first number toh chota ya barabar hai, par second number se chota hona chaye merger ke lye vrna koi mtlan nhi merge ka 
                a.second = p[i].second;
                s.pop(); // pop kra old vala
                s.push(a); // naya vala daal dya.
            }
        } else {
            s.push(p[i]); //push kra nya pair jb pair merge nhi ho skte the
        }
    }
    while(!s.empty()) {
        cout << s.top().first << " " << s.top().second << endl;
        s.pop();
    }
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
#endif
    mergeInterval();
    return 0;
}