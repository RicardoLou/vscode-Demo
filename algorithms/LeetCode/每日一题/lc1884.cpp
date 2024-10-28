#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int twoEggDrop(int n) {
        int i = 0;
        for(; n > 0; i ++) 
            n -= i;
        return i - 1;
    }
};