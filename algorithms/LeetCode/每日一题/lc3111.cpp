#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    static bool cmp(vector<int>& a, vector<int>& b) {
        return a[0] < b[0];
    }
    int minRectanglesToCoverPoints(vector<vector<int>>& points, int w) {
        sort(points.begin(), points.end(), cmp);
        int ans = 0;
        int start = -1;
        for(auto& x : points) {
            if(x[0] > start) {
                ans ++;
                start = x[0] + w;
            }
        }
        return ans;
    }
};