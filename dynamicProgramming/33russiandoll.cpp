#include<bits/stdc++.h>
using namespace std;

class Doll {
    public:
    int w;
    int h;
};

bool compare(Doll a, Doll b) {
    return a.w < b.w;
}

int russianDoll(vector<Doll>& b) {
    sort(b.begin(), b.end(), compare);
    int dp[b.size()];
    dp[0] = 1;
    for(int i = 1; i < b.size(); i++) {
        dp[i] = 1;
        for(int j = 0; j < i; j++) {
            if(b[i].h > b[j].h && b[i].w > b[j].w) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }
    int len = INT_MIN;
    for(auto x : dp) {
        if(len < x) len = x;
    }
    return len;
}

int main() {
    int n;
    cin >> n;
    vector<Doll> dolls;
    for(int i = 0; i < n; i++) {
        Doll b;
        cin >> b.w >> b.h;
        dolls.push_back(b);
    }
    cout << russianDoll(dolls) << endl;
    return 0;
}

// 11
// 17 5
// 26 18
// 25 34
// 48 84
// 63 72
// 42 86
// 9 55
// 4 70
// 21 45
// 68 76
// 58 51
// 5