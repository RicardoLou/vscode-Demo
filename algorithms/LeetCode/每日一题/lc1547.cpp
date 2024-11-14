#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minCost(int n, vector<int>& cuts) {
        // 将切割位置排序
        sort(cuts.begin(), cuts.end());
        // 调用递归函数从 0 到 n 的区间
        return minCostHelper(0, n, cuts);
    }
    // 递归辅助函数，计算从 start 到 end 的最小切割成本
    int minCostHelper(int start, int end, const vector<int>& cuts) {
        int cost = INT_MAX;
        // 遍历所有可能的切割点
        for (int cut : cuts) {
            if (cut > start && cut < end) {
                // 计算以 cut 为切割点的成本
                int left_cost = minCostHelper(start, cut, cuts);
                int right_cost = minCostHelper(cut, end, cuts);
                int total_cost = (end - start) + left_cost + right_cost;
                cost = min(cost, total_cost);
            }
        }
        // 如果没有有效切割点，则返回 0
        return (cost == INT_MAX) ? 0 : cost;
    }
};