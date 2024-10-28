#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool detectCapitalUse(string word) {
        int cnt = 0;
        for(int i = 0; i < word.length(); i ++) {
            if(isupper(word[i]))
                cnt ++;
        }
        return cnt == 0 || cnt == word.length() || (cnt == 1 && isupper(word[0]));
    }
};