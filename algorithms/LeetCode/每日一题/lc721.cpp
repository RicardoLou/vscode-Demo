#include<bits/stdc++.h>
using namespace std;
//https://leetcode.cn/problems/accounts-merge/?envType=daily-question&envId=2024-07-15

class Solution {
public:
    unordered_map<string, vector<int>> index;
    unordered_set<string> email_set;
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        //把每一个邮箱编号，同一个人的为同一号，同样的邮箱在同一个集合中
        for (int i = 0; i < accounts.size(); i++) {
            for (int j = 1; j < accounts[i].size(); j++) {
                index[accounts[i][j]].push_back(i);
            }
        }
        
        vector<vector<string>> ans;
        vector<bool> vis(accounts.size(), false);
        
        for (int i = 0; i < vis.size(); i++) {
            if (vis[i])
                continue;
            email_set.clear();
            dfs(vis, i, accounts);

            vector<string> res = {accounts[i][0]};
            //res的最后就是新加进来的姓名
            res.insert(res.end(), email_set.begin(), email_set.end());
            //对邮箱进行排序
            sort(res.begin() + 1, res.end());

            ans.push_back(res);
        }
        return ans;
    }

    void dfs(vector<bool>& vis, int i, vector<vector<string>>& accounts) {
        vis[i] = true;
        for (int j = 1; j < accounts[i].size(); j++) {
            string email = accounts[i][j];
            //如果这个邮箱保存过，也就是找到了同一个人拥有相同邮箱，这个邮箱不必要重复添加
            if (email_set.count(email))
                continue;
            //添加同一个人，但是有另一个人没有的邮箱
            email_set.insert(email);
            //遍历拥有同一个邮箱的每一个人
            for (int k : index[email]) {
                if (!vis[k]) {
                    dfs(vis, k, accounts);
                }
            }
        }
    }
};