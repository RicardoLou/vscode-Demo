#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int replace(int s, vector<int>& cards, int x, int cnt) {
        for(int i = cnt; i < cards.size(); i ++) {
            if(cards[i] % 2 != x % 2) {
                return s - x + cards[i];
            }
        }
        return 0;
    } 
    int maxmiumScore(vector<int>& cards, int cnt) {
        sort(cards.begin(), cards.end(), greater<int>());
        int s = 0;
        for(int i = 0; i < cnt; i ++) {
            s += cards[i];
        }
        if(s % 2 == 0)
            return s;
        int x = cards[cnt - 1];
        int ans = replace(s, cards, x, cnt);
        for(int i = cnt - 2; i >= 0; i --) {
            if(cards[i] % 2 != x % 2) {
                ans = max(ans, replace(s, cards, cards[i], cnt));
                break;
            }
        }
        return ans;

    }
};