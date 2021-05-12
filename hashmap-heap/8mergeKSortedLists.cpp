#include<bits/stdc++.h>
using namespace std;

class Pair {
    public:
    int li;
    int di;
    int data;
    Pair(int l, int d, int da) {
        li = l;
        di = d;
        data = da;
    }
 
};

class CompareData {
    public:
    bool operator()(Pair const&p1, Pair const&p2) {
        return p1.data > p2.data;
    }
};

vector<int> mergeKSortedLists(vector<vector<int>> lists) {
    priority_queue<Pair, vector<Pair>, CompareData> pq;

    //sare list ka pehla element dala with information of that element.
    //which is, list in which it belongs and index in that list.
    for(int i = 0; i < lists.size(); i++) {
        Pair p(i, 0, lists[i][0]);
        pq.push(p);
    }
    vector<int> mergedList;
    while(!pq.empty()) {
        Pair p = pq.top();
        mergedList.push_back(p.data);
        pq.pop();
        p.di++;
        //when ever we pop an element we check wether that element's 
        //list has other elements for next index
        //if it has push to the pq with all information
        //else it will continue for remaining lists.
        if(lists[p.li].size() > p.di)  {
            p.data = lists[p.li][p.di];
            pq.push(p);
        }
    }
    return mergedList;
}

// 3
// 4
// 10 20 30 40
// 5
// 5 9 12 18 32
// 3
// 11 15 17

// 5 9 10 11 12 15 17 18 20 30 32 40 

int main() {
    int n;
    cin >> n;
    vector<vector<int>> lists;
    for(int i = 0; i < n; i++) {
        int k;
        cin >> k;
        vector<int> list;
        for(int j = 0; j < k; j++) {
            int num;
            cin >> num;
            list.push_back(num);
        }
        lists.push_back(list);
    }
    vector<int> ans = mergeKSortedLists(lists);
    for(auto x : ans) cout << x << " ";
    cout << endl;

}