#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxHeightOfTriangle(int red, int blue) {
        int cnt[2]{};
        for(int i = 1; ; i ++) {
            cnt[i % 2] += i;
            if ((cnt[0] > red || cnt[1] > blue) && (cnt[0] > blue || cnt[1] > red)) {
                return i - 1;
            }
        }
    }
};