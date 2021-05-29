#include<bits/stdc++.h>
using namespace std;

// input helper functions ==> Start
int toInt(string s) {
    int d = 1;
    int num = 0;
    for(int i = s.size()-1; i>=0; i--){
        num += (s[i] - '0') * d;
        d = d * 10;
    }
    return num;
}

void fillArray(string& s1, vector<string>& q) {
    stringstream ss1(s1);
    string word;
    while(ss1 >> word) {
        q.push_back(word);
    }
}
// input helper functions ==> End

class CustomStack {
    int* value;
    int* inc;
    int ind;
    int maxSize;
    public:
    CustomStack(int maxSize) {
        value = new int[maxSize];
        inc = new int[maxSize];
        ind = -1;
        this->maxSize = maxSize;
    }
    void push(int val) {
        if(ind + 1 == maxSize) return;
        ind++;
        value[ind] = val;
        inc[ind] = 0;
    }
    int pop() {
        if(ind == -1) return -1;
        ind--;
        if(ind != -1) inc[ind] += inc[ind+1];
        return value[ind+1] + inc[ind+1];
    }
    void increment(int k, int val) {
        if(ind == -1) return;
        if(k-1 > ind) inc[ind] += val;
        else inc[k-1] += val;
    }
};

int main() {
    string maxSizeString;
    getline(cin, maxSizeString);
    int maxSize = toInt(maxSizeString);
    CustomStack cs(maxSize);
    vector<int> v;
    while(true) {
        string s;
        vector<string> task;
        getline(cin, s);
        fillArray(s, task);
        if(task[0] == "push"){
            cs.push(toInt(task[1]));
        }else if(task[0] == "pop"){
            v.push_back(cs.pop());
        }else if(task[0] == "increment"){
            cs.increment(toInt(task[1]), toInt(task[2]));
        }else{
            break;
        }
    }
    for(auto x : v) cout << x << endl;
    cout << "exit" << endl;
    return 0;
}