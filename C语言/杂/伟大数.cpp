#include<iostream>
using namespace std;
class Solution {
public:
    int maximizeGreatness(vector<int> &nums) {
        sort(nums.begin(), nums.end());
        int i = 0;
        for (int x : nums)
            if (x > nums[i])
                ++i;
        return i;
    }
};