#include<iostream>
using namespace std;

const int N = 100010;
int a[N], s[N];
int main() {
    int n, m, x;
    cin >> n >> m;
    for(int i = 1; i <= n; i ++) {
        cin >> x;
        s[i] = s[i - 1] + x;
    }
    while(m --) {
        int l, r;
        cin >> l >> r;
        cout << s[r] - s[l - 1] << endl;
    }
    return 0;
}