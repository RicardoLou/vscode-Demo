#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int ans = 0, min_s = 0, s = 0;
        for (int i = 0; i < gas.size(); i ++) {
            s += gas[i] - cost[i];
            if (s < min_s) {
                min_s = s;
                ans = i + 1; // 这时候已经到了下一个加油站了, 从最小出发一定不会出现比自己还好的方案
            }
        }
        return s < 0 ? -1 : ans;
    }
};