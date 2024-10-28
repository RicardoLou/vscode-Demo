#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int n;
    cin >> n;
    int ans = 0;
    for(int i = 1; i < n; i ++) {
        int t = i;
        bool flag = false;
        for(int j = 1; t != 0; j ++) {
            //位置是偶数的时候判断当前位置是否为偶数
            if(j % 2 == 0 && t % 10 % 2 != 0)
                flag = true;
            if(j % 2 != 0 && t % 10 % 2 == 0)
                flag = true;
            t /= 10;
        }
        if(!flag)
            ans ++;
    }
    cout << ans;
    return 0;
}