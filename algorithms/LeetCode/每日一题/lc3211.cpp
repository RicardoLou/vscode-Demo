#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void dfs(int i, int n, vector<string>& ans, string& path) {
        if (i == n) {
            ans.push_back(path);
            return;
        }
        // 这里不能pushback因为没有回溯
        path[i] = '1';
        dfs(i + 1, n, ans, path);
        if(i == 0 || path[i - 1] == '1') {
            path[i] = '0';
            dfs(i + 1, n, ans, path);
        }
    }
    vector<string> validStrings(int n) {
        vector<string> ans;
        string path(n, 0);
        dfs(0, n, ans, path);
        return ans;
    }
};