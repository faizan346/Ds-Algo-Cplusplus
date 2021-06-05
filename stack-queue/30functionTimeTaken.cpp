#include<bits/stdc++.h>
using namespace std;

int toInt(string s) {
    int d = 1;
    int num = 0;
    for(int i = s.size()-1; i>=0; i--){
        num += (s[i] - '0') * d;
        d = d * 10;
    }
    return num;
}

class Pair {
    public:
    int id;
    int startTime;
    int childTime;
    Pair(int i, int s, int c) {
        id = i;
        startTime = s;
        childTime = c;
    }
};

class Log {
    public:
    int id;
    string cycle;
    int timeStamp;
};

void tokenize(string s, string del, Log& log) {
    int start = 0;
    int end = s.find(del);
    int i = 0;
    while (end != -1) {
        if(i == 0) log.id = toInt(s.substr(start, end - start));
        if(i == 1) log.cycle = (s.substr(start, end - start));
        i++;
        start = end + del.size();
        end = s.find(del, start);
    }
    log.timeStamp = toInt(s.substr(start, end - start));
}

int main() {
    int n, len;
    cin >> n >> len;
    vector<Log> logs;
    vector<int> timeTaken(n, 0);
    for(int i = 0; i < len; i++) {
        string l;
        cin >> l;
        Log log;
        tokenize(l, ":", log);
        logs.push_back(log);
    }
    stack<Pair> st;
    for(auto log : logs) {
        if(log.cycle == "start") {
            st.push(Pair(log.id, log.timeStamp, 0));
        } else {
            Pair startLog = st.top();
            st.pop();
            int interval = log.timeStamp - startLog.startTime + 1;
            int time = interval - startLog.childTime;
            timeTaken[startLog.id] += time;
            if(!st.empty()) {
                st.top().childTime += interval;
            }
        }
    }
    for(auto x : timeTaken) cout << x << endl;
    return 0;
}