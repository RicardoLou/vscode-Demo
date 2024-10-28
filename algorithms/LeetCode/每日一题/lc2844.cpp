#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
//可以被25整除只有0 25 50 75
    int minimumOperations(string num) {
        int n = num.size();
        bool f0 = false, f5 = false;
        for(int i = n - 1; i >= 0; i --) {
            char c = num[i];
            if(f0 && (c == '0' || c == '5') || f5 && (c == '2' || c == '7'))
                return n - i - 2;
            if(c == '0')
                f0 = true;
            else if(c == '5')
                f5 = true;
        }
        return n - f0;
    }
};