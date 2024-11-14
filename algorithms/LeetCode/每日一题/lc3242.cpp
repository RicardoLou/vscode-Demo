#include<bits/stdc++.h>
using namespace std;

class NeighborSum {
public:
    vector<vector<int>> Grid;
    NeighborSum(vector<vector<int>>& grid) {
        Grid = grid;
    }
    
    int adjacentSum(int value) {
        int sum = 0;
        for(int i = 0; i < Grid.size(); i ++) {
            for(int j = 0; j < Grid[0].size(); j ++ ) {
                if (Grid[i][j] == value) {
                    sum += i - 1 >= 0 ? Grid[i - 1][j] : 0;
                    sum += i + 1 < Grid.size() ? Grid[i + 1][j] : 0;
                    sum += j - 1 >= 0 ? Grid[i][j - 1] : 0;
                    sum += j + 1 < Grid[0].size() ? Grid[i][j + 1] : 0;
                }
            }
        }
        return sum;
    }
    
    int diagonalSum(int value) {
        int sum = 0;
        for(int i = 0; i < Grid.size(); i ++) {
            for(int j = 0; j < Grid[0].size(); j ++ ) {
                if (Grid[i][j] == value) {
                    sum += (i - 1 >= 0 && j - 1 >= 0) ? Grid[i - 1][j - 1] : 0;
                    sum += (i + 1 < Grid.size() && j + 1 < Grid[0].size()) ? Grid[i + 1][j + 1] : 0;
                    sum += (i - 1 >= 0 && j + 1 < Grid[0].size()) ? Grid[i - 1][j + 1] : 0;
                    sum += (i + 1 < Grid.size() && j - 1 >= 0) ? Grid[i + 1][j - 1] : 0;
                }
            }
            
        }
        return sum;
    }
};

/**
 * Your NeighborSum object will be instantiated and called as such:
 * NeighborSum* obj = new NeighborSum(grid);
 * int param_1 = obj->adjacentSum(value);
 * int param_2 = obj->diagonalSum(value);
 */