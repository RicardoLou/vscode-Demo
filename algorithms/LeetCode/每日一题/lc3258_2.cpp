#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countKConstraintSubstrings(string s, int k) {
        int j = 0;
        int ans = 0;
        int cnt[2] = {0};
        for(int i = 0; i < s.length(); i ++) {
            cnt[s[i] & 1] ++;
            while(cnt[0] > k && cnt[1] > k) {
                cnt[s[j] & 1] --;
                j ++;
            }
            ans += i - j + 1;
        }
        return ans;
    }
};