#include<bits/stdc++.h>
using namespace std;

bool solve1(string s, int k) {
    vector<bool> map(k+1, false);
    if(k > s.size()*s.size()) return false;
    int num = 0;
    int j = -1;
    for(int i = 0; i < s.size(); i++) {
        char c = s[i];
        // adding digit to end
        num = num << 1;
        num = num | (s[i] - '0');

        while(j < i && (num > k || s[j + 1] == '0')) {
            j++;
            num = num & ~(1 << (i-j)); // off jth bit to 0
        }
        // checking all substring including ith pos
        int temp = num;
        for(int l = j+1; l <= i; l++) {
            map[temp] = true;
            temp = temp & ~(1 << (i-l));
        }
    }
    // check for 1 - k 
    map[0] = true;
    for(auto t : map) {
        if(t == false) {
            return false;
        }
    }
    return true;
}

bool solve(string s, int k) {
    int n = s.size();
    vector<bool> map(k+1, false);
    
    int val = 0;
    for(int i = 0; i < n; i++) {
        if(s[i] == '0') continue;
        int val = 0;
        string t = "";
        for(int j = 0; j < 31; j++) {
            if(i+j >= n) break;
            val = val << 1;
            val |= (int)(s[i+j] - '0');
            t += s[i+j];
            if(val <= k) map[val] = true;
            else break;
        }
    }
    // check for 1 - k 
    map[0] = true;
    for(auto t : map) {
        if(t == false) {
            return false;
        }
    }
    return true;
}
// 01101110010111011110001001101010111100110111101111101011011101111011111011111110
// 8
int main() {
    string s;
    cin >> s;
    int k;
    cin >> k;
    cout << (solve(s, k) ? "true" : "false") << endl;
    return 0;
}