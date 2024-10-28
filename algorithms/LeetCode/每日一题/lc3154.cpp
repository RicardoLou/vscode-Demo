#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    // i 当前位于哪一阶， j 当前使用了多少次操作2， down 表示上一次是否用过操作1
    auto dfs(int i, int j, bool down, unordered_map<long long, int>& memo, int k) {
        if(i > k + 1) 
            return 0;
        // 状态压缩
        auto mask = (long long) i << 32 | j << 1 | down;
        if(memo.contains(mask))
            return memo[mask];
        int ans = i == k;
        // 使用操作2
        ans += dfs(i + (1 << j), j + 1, false, memo, k);
        // 使用操作1
        if(i != 0 && !down)
            ans += dfs(i - 1, j, true, memo, k);
        memo[mask] = ans;
        return ans;
    }
    int waysToReachStair(int k) {
        unordered_map<long long, int> memo;
        return dfs(1, 0, false, memo, k);
    }
};