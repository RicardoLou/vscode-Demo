#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string losingPlayer(int x, int y) {
        bool ans = 1; // 0 表示Alice 1 表示Bob
        while(x >= 1 && y >= 4) {
            x -= 1;
            y -= 4;
            ans ^= 1;
        }
        return ans == 0 ? "Alice" : "Bob";
    }
};