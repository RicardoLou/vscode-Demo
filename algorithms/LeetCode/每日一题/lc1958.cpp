#include<bits/stdc++.h>

using namespace std;

class Solution {
    int dirs[8][2] = {{1, 0}, {1, 1}, {0, 1}, {-1, 1}, {-1, 0}, {-1, -1}, {0, -1}, {1, -1}};
public:
    bool checkMove(vector<vector<char>>& board, int rMove, int cMove, char color) {
        int n = board.size(), m = board[0].size();
        for(auto dir : dirs) {
            int x = rMove + dir[0], y = cMove + dir[1];
            if(x < 0 || x >= n || y < 0 || y >= m || board[x][y] == '.' || board[x][y] == color)
                continue;
            while(true) {
                //往两个方向延伸
                x += dir[0];
                y += dir[1];
                if(x < 0 || x >= n || y < 0 || y >= m || board[x][y] == '.') {
                    break;
                }
                if(board[x][y] == color)
                    return true;
            }
        }
        return false;
    }
};