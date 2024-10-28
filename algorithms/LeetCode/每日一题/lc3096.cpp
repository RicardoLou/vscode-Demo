#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumLevels(vector<int>& possible) {
        int s = 0;
        for(auto& i : possible) {
            if(i == 0)
                s --;
            else s ++;
        }
        int alice = 0;
        for(int i = 0; i < possible.size() - 1; i ++) {
            alice += possible[i] == 0 ? -1 : 1;
            //大于剩下Bob的部分了
            if(alice > s - alice)
                return i + 1;
        }
        return -1;
    }
};