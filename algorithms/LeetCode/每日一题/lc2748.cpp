#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int gcd(int a, int b) {
        return b == 0 ? a : gcd(b, a % b);
    }
    int countBeautifulPairs(vector<int>& nums) {
        int cnt[10]{};
        int ans = 0;
        for(int i = 0; i < nums.size(); i ++) {
            for(int j = 1; j < 10; j ++) {
                //找出与nums[j]的最后一个数字互质的数字，并且如果在nums中存在首位是这位数字的数就加上去
                if(cnt[j] > 0 && gcd(nums[i] % 10, j) == 1) {
                    ans += cnt[j];
                }
            }
            while(nums[i] >= 10) {
                nums[i] /= 10;
            }
            cnt[nums[i]] ++; // 最高位出现次数
        }
        return ans;
    }
};