#include<bits/stdc++.h>
using namespace std;

int arrangeBuilding(int n, int startWith, vector<vector<int>>& t) {
    if(n == 0) {
        return 1; // empty plot one way
    }
    if(t[n][startWith] != -1) return t[n][startWith];
    int ways;
    // 1 = space, 0 = building
    if(startWith == 1) {
        //if prev element not b then put curr as b and s
        ways = arrangeBuilding(n-1, 1, t)
            + arrangeBuilding(n-1, 0, t);
    } else {
        ways = arrangeBuilding(n-1, 1, t);
    }
    return t[n][startWith] = ways;
}

//constant space
int arrangeBuilding(int n) {
    int building = 1, space = 1; // ways possible when no element there is one i.e. empty plot.
    for(int i = 1; i < n+1; i++) {
        int temp = building;
        building = space; // if put curr ele put as building the next can only be space
        space = space + temp; // if put curr ele put as space next element can be space or building
    }
    return space;
}

int main() {
    int n;
    cin >> n;
    int waysForOneSideOfRoad, forBothSideComb;
    waysForOneSideOfRoad = arrangeBuilding(n);
    forBothSideComb = waysForOneSideOfRoad*waysForOneSideOfRoad;
    cout << forBothSideComb << endl;
    vector<vector<int>> t(n+1, vector<int>(2, -1));
    waysForOneSideOfRoad = arrangeBuilding(n, 1, t);
    forBothSideComb = waysForOneSideOfRoad*waysForOneSideOfRoad;
    cout << forBothSideComb << endl;

    return 0;
}