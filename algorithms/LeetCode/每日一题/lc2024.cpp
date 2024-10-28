#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxConsecutiveAnswers(string answerKey, int k) {
        int ans = 0, left = 0, cnt[2]{};
        for (int right = 0; right < answerKey.length(); right++) {
            cnt[answerKey[right] >> 1 & 1]++;
            //当两种同时超过操作数时，那么这一段窗口就没有办法通过k次操作变成一样的
            while (cnt[0] > k && cnt[1] > k) {
                cnt[answerKey[left++] >> 1 & 1]--;
            }
            ans = max(ans, right - left + 1);
        }
        return ans;
    }
};