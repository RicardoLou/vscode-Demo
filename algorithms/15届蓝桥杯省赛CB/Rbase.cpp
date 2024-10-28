#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int n;
    double d;
    cin >> n >> d;
    cout << round(d * pow(2, n));
    return 0;
}