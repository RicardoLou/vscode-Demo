#include<bits/stdc++.h>
using namespace std;

#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
        // 使用记忆化存储需求状态和其对应的最低费用
        unordered_map<string, int> memo;
        return dfs(price, special, needs, memo);
    }
    
    // 辅助函数，将 needs 数组转换为字符串，用于记忆化存储
    string needsToStr(const vector<int>& needs) {
        string res;
        for (int need : needs) {
            res += to_string(need) + ",";
        }
        return res;
    }
    
    // 递归函数，计算满足当前需求的最低费用
    int dfs(const vector<int>& price, const vector<vector<int>>& special, vector<int>& needs, unordered_map<string, int>& memo) {
        // 将需求转换为字符串，以便记忆化存储
        string key = needsToStr(needs);
        if (memo.count(key)) return memo[key];
        
        // 直接购买当前需求中所有物品的花费（不使用大礼包）
        int minCost = 0;
        for (int i = 0; i < needs.size(); ++i) {
            minCost += needs[i] * price[i];
        }
        
        // 尝试使用每一个大礼包
        for (auto& offer : special) {
            vector<int> updatedNeeds(needs);
            bool validOffer = true;
            // 检查是否可以使用当前礼包
            for (int i = 0; i < needs.size(); ++i) {
                // 如果礼包中的物品数量超过了需求数量，则无法使用该礼包
                if (updatedNeeds[i] < offer[i]) {
                    validOffer = false;
                    break;
                }
                // 更新需求，减少对应物品数量
                updatedNeeds[i] -= offer[i];
            }
            
            // 如果礼包有效，计算使用该礼包后的最小花费
            if (validOffer) {
                // 当前礼包的钱加上进一步寻找最小花费
                minCost = min(minCost, offer.back() + dfs(price, special, updatedNeeds, memo));
            }
        }
        
        // 记录当前需求对应的最小费用
        memo[key] = minCost;
        return minCost;
    }
};