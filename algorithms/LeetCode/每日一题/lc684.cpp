#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> p = vector<int>(1010, 0);
    int find(int x) {
        if(x != p[x])
            p[x] = find(p[x]); // 如果x不是祖宗的话，就继续找，找到祖宗后直接把x的祖宗指向最高点
        return p[x];
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        for(int i = 0; i < n; i ++) {
            p[i] = i;
        }
        // 因为是找最后出现闭环的那条边，所以从前往后，反之从后往前
        for(int i = 0; i < n; i ++) {
            // 是否属于同一个根，如果同一根那么说明出现环了
            if(find(edges[i][0]) == find(edges[i][1]))
                return edges[i];
            // 否则可以直接加进去
            else {
                p[find(edges[i][1])] = find(edges[i][0]);

            }
        }
        return {};
    }
};