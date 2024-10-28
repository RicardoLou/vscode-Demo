#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long minEnd(int n, int x) {
        // 可以将按位AND转换为集合思考，按位AND就是求交集，也就是所有数求交集
        // 如何满足结果为 x ？ 
        // x 转换为二进制中比特位上为1的位置，交集中的数字也需要为1，因为0AND任何数都为0，所以必然无法构造结果为 x
        // 如何保证结果最小？
        // 除了 x 中为1的位置以外，其他位置从小到大排列n个
        // n --;
        // int i = 0, j = 0;
        // long long ans = x;
        // while(n >> j) {
        //     if((ans >> i & 1) == 0) {
        //         // 空位
        //         // 把n的第j位填到ans中的第i位上
        //         // ans += (long long) (n >> j & 1) << i; 这种写法也是可以的
        //         ans |= (long long) (n >> j & 1) << i;
        //         j ++;
        //     }
        //     i ++;
        // }
        // return ans;
        
        // 做法2 直接枚举0的位置，将x取反后再进行lowbit枚举，就可以直接枚举每个空位，节约了经过1的时间
        n --;
        long long ans = x;
        int i = 0, j = 0;
        for(long long k = ~x, lowb; n >> j; k ^= lowb) {
            // lowbit操作
            lowb = k & -k;
            //如果当前位是0，那么相当于不填，如果是1，那么乘lowb还是lowb
            ans |= (long long) (n >> j & 1) * lowb;
            j ++;
        }
        return ans;
    }
};