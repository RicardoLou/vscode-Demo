#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    static const int N = 2000;
    vector<int> f = vector<int>(N, 0);
    int find(int x) {
        if(f[x] != x) 
            f[x] = find(f[x]);
        return f[x];
    }
    vector<int> getRemove(vector<vector<int>>& edges) {
        for(int i = 1; i < edges.size(); i ++) {
            f[i] = i;
        }
        for(int i = 0; i < edges.size(); i ++) {
            if (find(edges[i][0]) == find(edges[i][1]))
                return edges[i];
            f[find(edges[i][1])] = find(edges[i][0]);
        }
        return {};
    }
    bool isTree(vector<vector<int>>& edges, int deleteEdge) {
        for(int i = 1; i < edges.size(); i ++) {
            f[i] = i;
        }
        for(int i = 0; i < edges.size(); i ++) {
            // 遇到需要删的边就跳过不加入到并查集
            if (i == deleteEdge) continue;
            if (find(edges[i][0]) == find(edges[i][1])) return false; // 形成闭环了
            // 加入到并查集的图中
            f[find(edges[i][1])] = find(edges[i][0]);
        }
        return true;
    }
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        int inD[N] = {0};
        stack<int> vecStack; // 要找最后的答案，所以用栈后面先弹出的是最后出现的
        vector<int> vec;
        // 记录入度
        for(int i = 0; i < n; i ++) {
            inD[edges[i][1]] ++;
        }
        for(int i = n - 1; i >= 0; i --) {
            if(inD[edges[i][1]] == 2)
                vec.push_back(i);
        }
        if (vec.size() > 0) {
            if(isTree(edges, vec[0]))
                return edges[vec[0]];
            else return edges[vec[1]];
        }
        return getRemove(edges);
    }
};