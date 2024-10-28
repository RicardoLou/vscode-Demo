#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        priority_queue<int> pq;
        int ans = 0, i = 0;
        while(startFuel < target) {
            while(i < stations.size() && stations[i][0] <= startFuel) {
                pq.emplace(stations[i][1]);
                i ++;
            }
            if (!pq.empty()) {
                startFuel += pq.top();
                pq.pop();
                ans ++;
            } else 
                return -1;
        }
        return ans;
    }
};