#include<bits/stdc++.h>
using namespace std;

string topologicalSort(unordered_map<char, vector<char>> &graph) {

    int n = graph.size();
    unordered_map<char, int> indegree;
    char src;
    for(auto x : graph) {
        if(indegree.count(x.first) == 0) indegree[x.first] = 0;
        for(auto v : x.second) {
            if(indegree.count(v) == 0) indegree[v] = 1;
            else indegree[v]++;
        }
    }   
    string ans = "";
    queue<char> q;
    for(auto x : indegree) {
        if(x.second == 0) q.push(x.first);
    }
    int count = 0;
    while(!q.empty()) {
        char src = q.front();
        q.pop();
        count++;
        ans += src;
        for(auto nbr : graph[src]) {
            if(--indegree[nbr] == 0) q.push(nbr);
        }
    }
    if(count == graph.size()) {
        return ans;
    } else {
        return "";
    }
}

string solve(vector<string> &a, int n) {
    unordered_map<char, vector<char>> graph;
    int mlen = 0;
    for(int i = 0; i < n; i++) {
        string s;
        s = a[i];
        mlen = max(mlen, (int)s.size());
        for(auto c : s) {
            graph[c] = vector<char>();
        }
    }
    vector<bool> match(n, true);
    
    for(int i = 0; i < mlen; i++) {
        for(int j = 1; j < n; j++) {
            if(match[j] == true &&  a[j].size() == i && a[j-1].size() >= i) {
                return "";
            } else if(match[j] == true && i < a[j-1].size()) {
                if(a[j][i] == a[j-1][i]) {
                    match[j] = true;
                } else {
                    graph[a[j-1][i]].push_back(a[j][i]);
                    match[j] = false;
                }
            } else {
                match[j] = false;
            }
        }
    }
    
    return topologicalSort(graph); 
}

int main() {
    int n;
    cin >> n;
    vector<string> a(n, "");
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    cout << solve(a, n) << endl;
    return 0;
}