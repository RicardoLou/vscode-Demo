#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int duplicateNumbersXOR(vector<int>& nums) {
        vector<int> cnt(51);
        int ans = 0;
        for(int x : nums) {
            cnt[x] ++;
            if (cnt[x] > 1) {
                ans ^= x;
            }
        }
        return ans;
    }
};