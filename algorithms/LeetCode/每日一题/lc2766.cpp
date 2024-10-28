#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> relocateMarbles(vector<int>& nums, vector<int>& moveFrom, vector<int>& moveTo) {
        unordered_set<int> set(nums.begin(), nums.end());
        for(int i = 0; i < moveFrom.size(); i ++) {
            set.erase(moveFrom[i]);
            set.insert(moveTo[i]);
        }
        vector<int> ans(set.begin(), set.end());
        ranges::sort(ans);
        return ans;
    }
};