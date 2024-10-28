#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool check(vector<int>& time, int total, long long x) {
        long long sum = 0;
        for (int t : time) {
            // x 时间可以跑多少次
            sum += x / t;
            if (sum >= total) {
                return true;
            }
        }
        return false;
    }
    long long minimumTime(vector<int>& time, int totalTrips) {
        long long l = 0, r = (long long) 1e18;
        long long ans = 0;
        while(l <= r) {
            long mid = (l + r) / 2;
            if (check(time, totalTrips, mid)) {
                ans = mid;
                r = mid - 1; // 减少时间
            } else {
                l = mid + 1; // 增加时间
            }
        }
        return ans;
    }
};