#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumAddedInteger(vector<int>& nums1, vector<int>& nums2) {
        ranges::sort(nums1);
        ranges::sort(nums2);
        // 枚举保留 nums1[2] 或者 nums1[1] 或者 nums1[0]
        // 倒着枚举是因为 nums1[i] 越大答案越小，第一个满足的就是答案
        for (int i = 2; i > 0; i--) {
            int x = nums2[0] - nums1[i];
            // 在 {nums1[i] + x} 中找子序列 nums2
            int j = 0;
            for (int k = i; k < nums1.size(); k++) {
                if (nums2[j] == nums1[k] + x && ++ j == nums2.size()) {
                    return x;
                }
            }
        }
        // 题目保证答案一定存在
        return nums2[0] - nums1[0];
    }
};