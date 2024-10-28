#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minSpeedOnTime(vector<int>& dist, double hour) {
        int l = -1, r = (int) 1e7 + 1;
        while(l < r) {
            int mid = (l + r) / 2;
            if (check(mid, dist, hour)) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        return l == (int) 1e7 + 1 ? -1 : l;
    }
    bool check(int mid, vector<int>& dist, double hour) {
        double time = 0;
        for (int x : dist) {
            // 整点才可以上车
            time = ceil(time);
            time += (double) x / mid;
        }
        return hour >= time;
    }
};