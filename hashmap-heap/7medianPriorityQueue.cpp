#include<bits/stdc++.h>
using namespace std;

class MedianPriorityQueue {
    //handle smaller half elements
    priority_queue<int> lpq;
    //handle larger half elements
    priority_queue<int, vector<int>, greater<int>> rpq;
    public:
    //here my priority is to push in lpq if the item doesn't belong to right pq
    //as it the val should be greater min of rpq.
    //in all other cases push to left pq. 
    //but if the size diff between two pq exceeds 1 than shift the extra element
    //to the other pq.
    void push(int val) {
        if(rpq.size() > 0 && rpq.top() < val) {
            rpq.push(val);
            if(rpq.size() - lpq.size() == 2) {
                lpq.push(rpq.top());
                rpq.pop();
            }
        } else {
            lpq.push(val);
            if(lpq.size() - rpq.size() == 2) {
                rpq.push(lpq.top());
                lpq.pop();
            }
        }
    }
    //just pop from greater size pq as it has the median store in it
    //but when the size even the pop from left pq to get left median
    void pop() {
        if(size() == 0) {
            cout << "underflow..." << endl;
        } else if(lpq.size() >= rpq.size()) {
            lpq.pop();
        } else {
            rpq.pop();
        }
    }
    int top() {
        if(size() == 0) {
            cout << "underflow..." << endl;
            return -1;
        } else if(lpq.size() >= rpq.size()) {
            return lpq.top();
        } else {
            return rpq.top();
        }
    }
    int size() {
        return lpq.size() + rpq.size();
    }
    bool empty() {
        if(size() == 0) {
            return true;
        }
        return false;
    }
};

int main() {
    MedianPriorityQueue mpq;
    mpq.push(2);
    cout << mpq.top() << endl;
    mpq.push(9);
    cout << mpq.top() << endl;
    mpq.push(5);
    cout << mpq.top() << endl;
    mpq.push(1);
    cout << mpq.top() << endl;
    mpq.push(8);
    cout << mpq.top() << endl;
    mpq.push(7);
    cout << mpq.top() << endl;
    mpq.push(3);
    cout << mpq.top() << endl;
    return 0;
}