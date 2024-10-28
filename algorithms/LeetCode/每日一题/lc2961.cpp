#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int qmi(int x, int p, int c) {
        int t = 1;
        while(p != 0) {
            if(p & 1) t = t * x % c;
            p >>= 1;
            x = x * x % c;
        }
        return t;
    }
    vector<int> getGoodIndices(vector<vector<int>>& variables, int target) {
        vector<int> ans;
        for(int i = 0; i < variables.size(); i ++) {
            vector<int> temp = variables[i];
            if(qmi(qmi(temp[0], temp[1], 10), temp[2], temp[3]) == target) 
                ans.push_back(i);
        }
        return ans;
    }
};