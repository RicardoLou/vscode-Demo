#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    // c - a^2 = b ^ 2 
    bool judgeSquareSum(int c) {
        if(c == 0)
            return true;
        for(int i = 0; i <= sqrt(c); i ++) {
            int t = c - i * i;
            if(sqrt(t) == (int) sqrt(t))
                return true;
        }
        return false;
    }
};