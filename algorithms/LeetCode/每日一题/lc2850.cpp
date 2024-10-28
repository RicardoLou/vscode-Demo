#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumMoves(vector<vector<int>>& grid) {
        vector<pair<int, int>> a, b;
        for(int i = 0; i < grid.size(); i ++) {
            for(int j = 0; j < grid[0].size(); j ++) {
                if(grid[i][j]) {
                    //多余的点记录进去（要转出去的）
                    for(int k = 0; k < grid[i][j] - 1; k ++) {
                        a.push_back(make_pair(i, j));
                    }
                } else {
                    b.push_back(make_pair(i, j));
                }
            }
        }
        int ans = 0x3f3f3f3f;
        do {
            int sum = 0;
            for(int i = 0; i < a.size(); i ++) {
                sum += abs(a[i].first - b[i].first) + abs(a[i].second - b[i].second);
            }
            ans = min(ans, sum);
            //枚举全排列，看哪种选择最佳
        } while(next_permutation(a.begin(), a.end()));
        return ans;
    }
};