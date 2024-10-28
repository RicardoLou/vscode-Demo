#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int dfs(int x, std::vector<int>& rewardValues, std::unordered_map<int, int>& memo) {
        // 如果当前奖励的最大值已经计算过
        // 如果x不在memo中，memo.find会返回memo.end()
        if (memo.find(x) != memo.end()) return memo[x];

        int maxReward = x;
        for (int reward : rewardValues) {
            if (reward > x) {
                maxReward = max(maxReward, dfs(x + reward, rewardValues, memo));
            }
        }
        memo[x] = maxReward;
        return maxReward;
    }
    int maxTotalReward(vector<int>& rewardValues) {
        unordered_map<int, int> memo;
        return dfs(0, rewardValues, memo);  // 从初始奖励 x = 0 开始递归搜索
    }
};