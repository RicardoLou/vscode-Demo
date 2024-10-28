#include<bits/stdc++.h>
#include <vector>
using namespace std;

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        if(obstacleGrid[0][0] == 1) return 0;  // 如果起点有障碍物，无法到达终点

        int m = obstacleGrid.size();           // 行数
        int n = obstacleGrid[0].size();        // 列数
        
        vector<vector<int>> dp(m, vector<int>(n, 0)); // 初始化 dp 数组为 m*n 大小，初始值为 0
        dp[0][0] = 1;  // 起点路径数初始化为1

        // 填充第一行
        for(int j = 1; j < n; j++) {
            if(obstacleGrid[0][j] == 1) {
                dp[0][j] = 0; // 如果有障碍物，路径数为0
            } else {
                dp[0][j] = dp[0][j-1]; // 没有障碍物，继承左边格子的路径数
            }
        }

        // 填充第一列
        for(int i = 1; i < m; i++) {
            if(obstacleGrid[i][0] == 1) {
                dp[i][0] = 0; // 如果有障碍物，路径数为0
            } else {
                dp[i][0] = dp[i-1][0]; // 没有障碍物，继承上边格子的路径数
            }
        }

        // 填充剩余部分的 dp 数组
        for(int i = 1; i < m; i++) {
            for(int j = 1; j < n; j++) {
                if(obstacleGrid[i][j] == 1) {
                    dp[i][j] = 0;  // 有障碍物，路径数为0
                } else {
                    dp[i][j] = dp[i-1][j] + dp[i][j-1];  // 没有障碍物，路径数等于上方和左方路径数之和
                }
            }
        }

        return dp[m-1][n-1];  // 返回到达终点的路径数
    }
};