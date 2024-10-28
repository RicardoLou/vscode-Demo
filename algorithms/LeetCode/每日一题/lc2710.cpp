#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string removeTrailingZeros(string num) {
        int cnt = 0;
        for(int i = num.length() - 1; i >= 0; i --) {
            if(num[i] == '0')
                cnt ++;
            else break;
        }
        return num.substr(0, num.length() - cnt);
    }
};