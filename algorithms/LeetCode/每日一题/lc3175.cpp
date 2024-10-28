#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    deque<int> q;
    // 记录每个胜出的次数
    unordered_map<int, int> mp;
    int findWinningPlayer(vector<int>& skills, int k) {
        int idx = 0, mk = 0;
        // 找到最大的下标
        for (int i = 0; i < skills.size(); i++) {
            q.push_back(i);
            if (skills[i] > mk) {
                mk = skills[i];
                idx = i;
            }
        }
        // 如果要赢过所有人一次，那么只能是找到的最大的下标
        if (k >= skills.size()) {
            return idx;
        }

        while (1) {
            // 把前两个取出来
            int a = q.front();
            q.pop_front();
            int b = q.front();
            q.pop_front();

            if (skills[a] > skills[b]) {
                q.push_front(a);
                q.push_back(b);
                mp[a]++;
                if (mp[a] >= k) {
                    return a;
                }
            } else {
                q.push_front(b);
                q.push_back(a);
                mp[b]++;
                if (mp[b] >= k) {
                    return b;
                }
            }
        }
        return 0;
    }
};