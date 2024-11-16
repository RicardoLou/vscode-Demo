#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minFlips(vector<vector<int>>& grid) {
        int ansc = 0;
        int ansr = 0;
        for(int i = 0; i < grid.size(); i ++) {
            for(int j = 0, k = grid[0].size() - 1; j < k; j ++, k --) {
                if(grid[i][j] != grid[i][k])
                    ansc ++;
            }
        }
        for(int i = 0; i < grid[0].size(); i ++) {
            for(int j = 0, k = grid.size() - 1; j < k; j ++, k --) {
                if(grid[j][i] != grid[k][i])
                    ansr ++;
            }
        }
        return min(ansc, ansr);
    }
};