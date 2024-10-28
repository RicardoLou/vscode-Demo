#include<bits/stdc++.h>

using namespace std;

int main() {
    //五行五列， 初始值是10
    // vector<vector<int>> dp(5, vector<int>(5, 10));
    vector<int> dp(10, 5);
    dp.push_back(1);
    cout << dp.size() << endl;
    dp.push_back(1);
    cout << dp[0] << " " << dp[1] << endl;
    dp.push_back(4);
    for(auto a : dp) 
        cout << a << " ";
}