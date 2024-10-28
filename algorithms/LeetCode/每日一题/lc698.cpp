#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        // 累加和
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if(sum % k) 
            return false;
        int target = sum / k; // 每一组最大容量
        sort(nums.begin(), nums.end());
        vector<int> arr(k, target); // k个组，每组可以容纳target的容量
        return dfs(nums, arr, k, 0);
    }
    bool dfs(vector<int>& nums, vector<int>& arr, int k, int index) {
        if(index >= nums.size()) return true;
        for(int i = 0; i < k; i ++) {
            if(nums[index] > arr[i]) continue;//如果当前数字大于剩余容量
            if(i > 0 && arr[i] == arr[i - 1]) continue;
            arr[i] -= nums[index];
            if(dfs(nums, arr, k, index + 1)) return true;
            // 回溯
            arr[i] += nums[index];
        }
        return false;
    }
};