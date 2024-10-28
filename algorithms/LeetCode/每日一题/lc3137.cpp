#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumOperationsToMakeKPeriodic(string word, int k) {
        int n = word.size();
        int mx = 0;
        unordered_map<string, int> cnt;
        for(int i = k; i <= n; i += k) {
            string temp = word.substr(i - k, k);
            cnt[temp] ++;
            mx = max(mx, cnt[temp]);
        }
        //因为只能从1k，2k，3k中选，所以选择较少的那些长为k的字符串变成最多的，就是正解
        return n / k - mx;
    }
};