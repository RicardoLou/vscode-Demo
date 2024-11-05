#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    int bitCount(int x) {
        int count = 0;
        while(x) {
            count += x & 1;
            x >>= 1;
        }
        return count;
    }
    int minChanges(int n, int k) {
        if((n & k) != k) {
            return -1;
        }
        return bitCount(n ^ k);
    }
};