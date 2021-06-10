#include<bits/stdc++.h>
using namespace std;
class Edge {
    public:
    int nbr;
    int bus;
    Edge() {}
    Edge(int n , int b) {
        nbr = n;
        bus = b;
    }
};

class Pair {
    public:
    int bus;
    int busesTaken;
    int src;
    Pair(int s, int b, int bt) {
        src = s, bus = b, busesTaken = bt;
    }
};

class CompareBusesTaken {
    public:
    bool operator()(Pair const& a, Pair const& b) {
        return a.busesTaken > b.busesTaken;
    }
};

class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, unordered_map<int, vector<int>>& inRoute
                              , int src, int tar) {
        
        queue<pair<int, int>> bfs;
        bfs.push({src, 0});
        unordered_set<int> visStops;
        unordered_set<int> visRoutes;
        while(!bfs.empty()) {
            pair<int, int> p = bfs.front();
            bfs.pop();
            int stop = p.first;
            int bsf = p.second; // buses so far.
            //cout << "stop = " << stop << " bsf = " << bsf << endl;
            if(visStops.count(stop) == 1) continue;
            if(stop == tar) return bsf;
            visStops.insert(stop);
            for(auto route : inRoute[stop]) {
                if(visRoutes.count(route) == 0) {
                    //cout << "route = " << route << endl;
                    visRoutes.insert(route);
                    for(auto stopLinkRoute : routes[route]) {
                        if(visStops.count(stopLinkRoute) == 0) {
                            bfs.push({stopLinkRoute, bsf + 1});
                        }
                    }
                }
            }
        }
        return -1;
    }
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        unordered_map<int , vector<int>> inRoute;
        for(int i = 0 ; i < routes.size(); i++) {
            for(auto stop : routes[i]) {
                inRoute[stop].push_back(i);
            }
        }
        
        return numBusesToDestination(routes, inRoute, source, target);
    }
};

int main() {

    return 0;
}