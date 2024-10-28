#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minOperations(vector<int>& nums) {
        int cnt = 0;
        for(int i = 0; i < nums.size(); i ++) {
            // 如果操作奇数次，并且当前是1 那么就需要操作，因为变 0 了
            // 如果操作偶数次，并且当前是1 那么不需要操作
            // 如果操作奇数次，并且当前是0 那么不需要操作
            // 如果操作偶数次，并且当前是0 那么需要操作，因为还是 0
            if(nums[i] == cnt % 2)
                cnt ++;
        }
        return cnt;
    }
};