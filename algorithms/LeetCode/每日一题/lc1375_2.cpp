#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findWinningPlayer(vector<int>& skills, int k) {
        int cnt = 0, i = 0, ans = 0;
        int n = skills.size();
        while(i < n) {
            int j = i + 1;
            while(j < n && skills[i] > skills[j] && cnt < k) {
                cnt ++;
                j ++;
            }
            if(cnt == k)
                return i;
            cnt = 1; // 如果 i 不是 0 那么第 i 个玩家一定赢过一次
            ans = i; // 记录一下，否则最后会因为j变化变化了
            i = j;
        }
        return ans;
    }
};