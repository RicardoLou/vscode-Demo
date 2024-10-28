#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> modifiedMatrix(vector<vector<int>>& matrix) {
        //可以优化为O(n^2 + n)，先预处理出来每一列的最大值即可
        for(int i = 0; i < matrix.size(); i ++) {
            for(int j = 0; j < matrix[0].size(); j ++) {
                if(matrix[i][j] == -1) {
                    int p = j;
                    for(int k = 0; k < matrix.size(); k ++) {
                        matrix[i][j] = max(matrix[i][j], matrix[k][p]);
                    }
                }
            }
        }
        return matrix;
    }
};