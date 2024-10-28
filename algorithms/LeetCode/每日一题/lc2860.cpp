#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countWays(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int ans = nums[0] > 0; // 如果大于0就有一个也不选的选择
        ans ++; //根据数据可知一定都可以选
        for(int i = 1; i < nums.size(); i ++) {
            if(nums[i - 1] < i && nums[i] > i) {
                ans ++;
            }
        }
        return ans;
    }
};