#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

// 高精度计算A *= x
void f(vector<int>& A, int x) {
    int t = 0;
    for(int i = 0; i < A.size(); i ++) {
        t += A[i] * x;
        A[i] = t % 10;
        t /= 10;
    }
    if(t) A.push_back(t);
}

void add(vector<int>& A, int k, int x) {
    int t = x;
    for(int i = k; i < A.size(); i ++) {
        t += A[i];
        A[i] = t % 10;
        t /= 10;
    }
    if (t) A.push_back(t);
}

int main() {
    int n;
    string s;
    cin >> n >> s;

    // 逆转之后方便计算高精度
    reverse(s.begin(), s.end());
    int dot = s.find('.');
    vector<int> A;
    for(char x : s) {
        if(x != '.')
            A.push_back(x - '0');
    }
    f(A, n);
    // 四舍五入
    if (A[dot - 1] > 5) add(A, dot, 1);
    for(int i = A.size(); i >= dot; i --) {
        cout << A[i];
    }
    return 0;
}