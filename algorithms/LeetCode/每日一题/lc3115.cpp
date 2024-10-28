#include<bits/stdc++.h>
using namespace std;

const int N = 110;
bool unprime[N];

class Solution {
public:
    int maximumPrimeDifference(vector<int>& nums) {
        init();
        int i = 0;
        while(unprime[nums[i]]) {
            i ++;
        }
        int j = nums.size() - 1;
        while(unprime[nums[j]]) {
            j --;
        }
        return j - i;
    }
    void init() {
        unprime[1] = true;
        for(int i = 2; i * i <= N; i ++) {
            if(unprime[i]) continue;
            for(int j = i * i; j < N; j += i) {
                unprime[j] = true;
            }
        }
    }
};