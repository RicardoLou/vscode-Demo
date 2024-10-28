#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canMakeSquare(vector<vector<char>>& grid) {
        int t[4][2] = {{0, 0}, {0, 1}, {1, 0}, {1, 1}};
        bool flag = true;
        for(int i = 0; i < 2; i ++) {
            for(int j = 0; j < 2; j ++) {
                int w = 0, b = 0;
                for(int k = 0; k < 4; k ++) {
                    int x = t[k][0];
                    int y = t[k][1];
                    if(grid[x + i][y + j] == 'B')
                        b ++;
                    else 
                        w ++;
                }
                if(b <= 1 || w <= 1)
                    return true;
            }
        }
        return false;
    }
};