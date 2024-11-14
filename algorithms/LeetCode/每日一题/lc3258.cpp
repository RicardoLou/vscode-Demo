#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countKConstraintSubstrings(string s, int k) {
        int ans = 0;
        for(int i = 0; i < s.size(); i ++) {
            int cnt0 = 0;
            int cnt1 = 0;
            for(int j = i; j < s.size(); j ++) {
                if(s[j] == '0')
                    cnt0 ++;
                else 
                    cnt1 ++;
                if(cnt0 > k && cnt1 > k) 
                    break;
                ans ++;
            }
        }
        return ans;
    }
};