#include<bits/stdc++.h>
using namespace std;

void celebrity() {
    int n;
    cin >> n;
    int r[n][n];
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> r[i][j];
        }
    }
    stack<int> s;
    for(int i = 0; i < n; i++) { //push every person in stack
        s.push(i);
    }
    while(s.size() > 1) { //let only those people stay who are potCeleb
        int a = s.top();
        s.pop();
        int b = s.top();
        s.pop();
        if(r[a][b] == 1) { //if a knows b than a can't be pot celeb
            s.push(b);
        } else {
            s.push(a); //if a don't know b b can't be pot celeb
        }
    }
    int potCeleb = s.top(); //only potential celeb that is possible
    for(int i = 0; i < n; i++) { //check weather the potential celeb is known by everone and he doen't know anyone
        if(i != potCeleb) {
            if(r[i][potCeleb] == 0 || r[potCeleb][i] == 1) {
                cout << "no celebrity found" << endl;
                return;
            }
        }
    }
    cout << "celebrity => " << potCeleb << endl;
}
// 4
// 0 1 1 1
// 1 0 1 0
// 0 0 0 0
// 1 1 1 0
// celebrity => 2
int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
#endif
    celebrity();
    return 0;
}