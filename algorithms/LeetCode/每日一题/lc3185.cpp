#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long countCompleteDayPairs(vector<int>& hours) {
        int cnt[24]{};
        long long ans = 0;
        for(int x : hours) {
            // 看左边有多少个可以匹配的，如果x=1，那么23，47都可以匹配上，所以使用模除统计
            ans += cnt[(24 - x % 24) % 24];
            cnt[x % 24] ++;
        }
        return ans;
    }
};