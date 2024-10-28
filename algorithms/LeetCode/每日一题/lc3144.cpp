#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int dfs(int i, string& s, vector<int>& memo) {
        if(i < 0) {
            return 0;
        }
        if(memo[i] > 0) {
            return memo[i];
        }
        int ans = INT_MAX;
        int k = 0;
        int cnt[26]{};
        int MaxCnt = 0;
        for(int j = i; j >= 0; j --) {
            k += cnt[s[j] - 'a'] ++ == 0;
            MaxCnt = max(MaxCnt, cnt[s[j] - 'a']);
            if(i - j + 1 == k * MaxCnt) {
                ans = min(ans, dfs(j - 1, s, memo) + 1);
                
            }
        }
        memo[i] = ans;
        return ans;
    }
    // 当且仅当s中子串长度等于k种字母*字母出现次数最大值
    int minimumSubstringsInPartition(string s) {
        int n = s.size();
        vector<int> memo(n);
        return dfs(n - 1, s, memo);
    }
};