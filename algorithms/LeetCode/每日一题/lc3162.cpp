#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numberOfPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        unordered_map<int, int> cnt;
        for (int x : nums1) {
            if (x % k)
                continue;
            // x 能被 nums2[i] * k 整除 等价于 x / k 能被 nums2[i] 整除
            x /= k;
            for (int i = 1; i * i <= x; i ++) {
                // 如果 i 不是 x 的因子
                if (x % i) {
                    continue;
                }
                cnt[i] ++;
                // 统计因子， 如果 i 是 x 的因子，那么 x / i 也一定是
                if (i * i < x) {
                    cnt[x / i] ++;
                }
            }
        }
        int ans = 0;
        for(int x : nums2) {
            ans += cnt.contains(x) ? cnt[x] : 0;
        }
        return ans;
    }
};