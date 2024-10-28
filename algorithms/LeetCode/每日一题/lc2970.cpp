#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int incremovableSubarrayCount(vector<int>& nums) {
        int n = nums.size();
        int i = 0;
        while(i < n - 1 && nums[i] < nums[i + 1]) {
            i ++;
        }
        //特判整个数组都是严格递增的时候
        if(i == n - 1) {
            return n * (n + 1) / 2;
        }
        int ans = i + 2;
        for(int j = n - 1; j == n - 1 || nums[j] < nums[j + 1]; j --) {
            while(i >= 0 && nums[i] >= nums[j])
                i --;
            ans += i + 2;
        }
        return ans;
    }
};