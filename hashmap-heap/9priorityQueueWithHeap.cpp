#include<bits/stdc++.h>
using namespace std;

class PriorityQueue {
    vector<int> v;
    //iterative
    void upHeapify() {
        int child = size()-1;
        while(child != 0) {
            int parent = (child-1)/2;
            if(v[parent] > v[child]) {
                swap(v[parent], v[child]);
                child = parent;
            } else {
                break;
            }
        }
    }
    //recursive
    void upHeapify(int child) {
        if(child == 0) return;
        int parent = (child-1)/2;
        if(v[parent] > v[child]) {
            swap(v[parent], v[child]);
            upHeapify(parent);
        }
    }
    //recursive
    void downHeapify(int i) {
        int leftChild = 2 * i + 1;
        int rightChild = 2 * i + 2;
        int minInd = i;
        if(leftChild < size() && v[leftChild] < v[minInd]) {
            minInd = leftChild;
        }
        if(rightChild < size() && v[rightChild] < v[minInd]) {
            minInd = rightChild;
        }
        if(minInd != i) {
            swap(v[i], v[minInd]);
            downHeapify(minInd);
        }
    }
    //iterative
    void downHeapify() {
        int i = 0;
        while(true) {
            int leftChild = 2 * i + 1;
            int rightChild = 2 * i + 2;
            int minInd = i;
            if(leftChild < size() && v[leftChild] < v[minInd]) {
                minInd = leftChild;
            }
            if(rightChild < size() && v[rightChild] < v[minInd]) {
                minInd = rightChild;
            }
            if(minInd != i) {
                swap(v[i], v[minInd]);
                i = minInd;
            } else {
                break;
            }
        }
    }
    public:
    PriorityQueue() {}
    PriorityQueue(int *a, int n) {
        for(int i = 0 ; i < n; i++) {
            v.push_back(a[i]);
        }
        for(int i = n/2 - 1; i >= 0; i--) {
            downHeapify(i);
        }
    }
    void push(int val) {
        v.push_back(val);
        //upHeapify(size()-1);
        upHeapify();
    }
    void pop() {
        if(size() == 0) {
            cout << "underflow.." << endl;
            return;
        }
        swap(v[0], v[size()-1]);
        v.pop_back();
        //downHeapify(0);
        downHeapify();
    }
    int top() {
        if(size() == 0) {
            cout << "underflow.." << endl;
            return -1;
        }
        return v[0];
    }
    int  size() {
        return v.size();
    }
    bool empty() {
        if(size() == 0) {
            return true;
        }
        return false;
    }
};

int main() {
    // int a[] = {32,51,6,12,66,12,9,10};
    // int n = sizeof(a)/sizeof(a[0]);
    // PriorityQueue pq(a, n);
    PriorityQueue pq;
    pq.push(53);
    cout << pq.top() << endl;
    pq.push(32);
    cout << pq.top() << endl;
    pq.push(23);
    cout << pq.top() << endl;
    pq.push(11);
    cout << pq.top() << endl;
    pq.push(66);
    cout << pq.top() << endl;
    pq.push(10);
    cout << pq.top() << endl;
    cout << endl;
    cout << pq.top() << endl;
    pq.pop();
    cout << pq.top() << endl;
    pq.pop();
    cout << pq.top() << endl;
    pq.pop();
    cout << pq.top() << endl;
    pq.pop();
    cout << pq.top() << endl;
    pq.pop();
    cout << pq.top() << endl;
    pq.pop();

}