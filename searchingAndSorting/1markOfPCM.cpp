#include<bits/stdc++.h>
using namespace std;

class marks {
    public:
    int phy;
    int chem;
    int math;
};

bool compare(marks &a, marks &b) {
    if(a.phy != b.phy) {
        return a.phy < b.phy;
    } else if(a.chem != b.chem) {
        return a.chem > b.chem;
    } else {
        return a.math < b.math;
    }
}

int main() {
    int n;
    cin >> n;
    vector<marks> m(n, marks());
    for(int i = 0; i < n; i++) {
        cin >> m[i].phy;
    }
    for(int i = 0; i < n; i++) {
        cin >> m[i].chem;
    }
    for(int i = 0; i < n; i++) {
        cin >> m[i].math;
    }
    
    sort(m.begin(), m.end(), compare);
    for(auto x : m) {
        cout << x.phy << " " << x.chem << " " << x.math << endl;
    }
    return 0;
}