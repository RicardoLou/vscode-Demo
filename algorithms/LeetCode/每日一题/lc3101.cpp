#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    long long countAlternatingSubarrays(vector<int>& nums) {
        long long ans = 0;
        int cnt = 0;
        for(int i = 0; i < nums.size(); i ++) {
            // 不等于可以叠加
            if(i > 0 && nums[i] != nums[i - 1])
                cnt ++;
            // 等于就只有自己一个
            else cnt = 1;
            ans += cnt;
        }
        return ans;
    }
};