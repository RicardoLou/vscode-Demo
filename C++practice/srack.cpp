#include<bits/stdc++.h>
using namespace std;
int main() {
    stack<int> s;
    s.push(2);
    s.push(4);
    int avg = 0;
    int n = s.size();
    for(int i = 0; i < n; i ++) {
        cout << s.top() << " ";
        avg += s.top();
        s.pop();
    }
    avg = avg / n;
    cout << avg << endl;
    return 0;
}