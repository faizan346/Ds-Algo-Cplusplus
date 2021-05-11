#include<bits/stdc++.h>
using namespace std;

void solveByMe(int *a, int n) {
    int min = INT_MAX;
    int max = INT_MIN;
    for(int i = 0; i < n; i++) {
        if(a[i] < min) {
            min = a[i];
        }
        if(a[i] > max) {
            max = a[i];
        }
    }
    unordered_map<int, int> umap;
    for(int i = 0; i < n; i++) {
        umap[a[i]] = 1;
    }
    vector<int> *ans = new vector<int>();
    vector<int> *temp = new vector<int>();
    for(int i = min; i <= max; i++) {
        if(umap[i] == 1) {
            temp->push_back(i);
        } else {
            if(temp->size() > ans->size()) {
                delete ans;
                ans = temp;
                temp = new vector<int>();
            } else {
                delete temp;
                temp = new vector<int>();
            }
        }
    }
    for(auto x : *ans) {
        cout << x << " ";
    }
    cout << endl;
}

void solveSir(int *a, int n) {
    unordered_map<int, bool> umap;
    for(int i = 0; i < n; i++) {
        umap[a[i]] = true;
    }
    //leave only consequitive subsequence starting elements as true
    //mark every other element as false.
    for(int i = 0; i < n; i++) {
        //if has element before it than it can't be starting element
        if(umap.find(a[i]-1) != umap.end()) {
            umap[a[i]] = false;
        }
    }
    int mainStartingPoint = 0;
    int mainLength = 0;
    for(int i = 0; i < n; i++) {
        if(umap[a[i]] == true) {
            int tempStartingPoint = a[i];
            int tempMainLen = 1;
            while(umap.find(tempStartingPoint+tempMainLen) != umap.end()) {
                tempMainLen++;
            }
            if(tempMainLen > mainLength) {
                mainLength = tempMainLen;
                mainStartingPoint = tempStartingPoint;
            }
        }
    }
    for(int i = 0; i < mainLength; i++) {
        cout << mainStartingPoint + i << " ";
    }
    cout << endl;
}

int main() {
    int n;
    cin >> n;
    int a[n];
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    //solveByMe(a, n);
    solveSir(a, n);
    return 0;
}