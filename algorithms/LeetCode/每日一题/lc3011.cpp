#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int bitCnt(int x) {
        int cnt = 0;
        while(x) {
            if(x & 1 == 1) cnt ++;
            x >>= 1;
        }
        return cnt;
    }
    bool canSortArray(vector<int>& nums) {
        int n = nums.size();
        for(int i = 0; i < n;) {
            int start = i;
            int cnt = bitCnt(nums[i ++]);
            while(i < n && bitCnt(nums[i]) == cnt)
                i ++;
            sort(nums.begin() + start, nums.begin() + i);
        }
        for(int i = 0; i < n - 1; i ++) {
            if(nums[i] > nums[i + 1])
            return false;
        }
        return true;
    }
};