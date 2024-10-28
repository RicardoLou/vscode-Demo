#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int f(int a, int b) {
        if(a > b) return 1; // 下降
        else if(a == b) return 2; // 平稳
        else return 3; // 上升
    }
    int temperatureTrend(vector<int>& temperatureA, vector<int>& temperatureB) {
        int cnt = 0;
        int ans = 0;
        int n = temperatureA.size();
        for(int i = 0; i < n - 1; i ++) {
            if(f(temperatureA[i], temperatureA[i + 1]) == f(temperatureB[i], temperatureB[i + 1]))
                cnt ++;
            else cnt = 0;
            ans = max(ans, cnt);
        }
        return ans;
    }
};