#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long maxStrength(vector<int>& nums) {
        long long Max = nums[0], Min = Max;
        for(int i = 1; i < nums.size(); i ++) {
            long long x = nums[i];
            long long temp = Min;
            Min = min(min(Min, x), min(Min * x, Max * x));
            Max = max(max(Max, x), max(temp * x, Max * x));
        }
        return Max;
    }
};