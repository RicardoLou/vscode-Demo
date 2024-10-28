#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long sumDigitDifferences(vector<int>& nums) {
        long long ans = 0;
        vector<vector<int>> map(to_string(nums[0]).length(), vector<int>(10, 0));
        for(int k = 0; k < nums.size(); k ++) {
            int x = nums[k];
            for(int i = 0; x > 0; x /= 10, i ++) {
                // 看从当前位置开始往左，有多少个和自己相同的，拿所有数减去相同的就是不同的
                ans += k - map[i][x % 10];
                map[i][x % 10] ++;
            }
        }
        return ans;
    }
};