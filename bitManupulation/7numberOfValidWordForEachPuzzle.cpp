#include<bits/stdc++.h>
using namespace std;

void solve(vector<string>& words, vector<string>& puzzles, int n, int m) {
    vector<int> wb(n, 0);
    for(int i = 0; i < n; i++) {
        for(auto ch : words[i]) {
            int onMask = 1 << (ch - 'a');
            wb[i] = wb[i] | onMask;
        }
    }
    vector<int> pb(m, 0);
    for(int i = 0; i < m; i++) {
        for(auto ch : puzzles[i]) {
            int onMask = 1 << (ch - 'a');
            pb[i] = pb[i] | onMask;
        }
    }
    unordered_map<char, vector<int>> umap; // char, wb
    for(int i = 0; i < n; i++) {
        unordered_set<char> us;
        for(auto ch : words[i]) {
            if(us.count(ch) == 0) {
                umap[ch].push_back(wb[i]);
                us.insert(ch);
            }
        }
    }
    for(int i = 0; i < m; i++) {
        char firstCh = puzzles[i][0];
        int count = 0;
        for(auto w : umap[firstCh]) {
            if((pb[i] & w) == w) {
                count++;
            }
        }
        cout << puzzles[i] << " -> " << count << endl;
    }
}

int main() {
    int n;
    cin >> n;
    vector<string> words(n, "");
    for(int i = 0; i < n; i++) {
        cin >> words[i];
    }
    int m;
    cin >> m;
    vector<string> puzzles(m, "");
    for(int i = 0; i < m; i++) {
        cin >> puzzles[i];
    }
    solve(words, puzzles, n, m);
    return 0;
}