#include<bits/stdc++.h>

using namespace std;

int main() {
    queue<int> q;
    q.push(1);
    q.push(2);
    q.push(4);
    cout << q.front() << endl;
    cout << q.back() << endl;
    q.pop();
    cout << q.front() << endl;
    cout << q.back() << endl;
    q.pop();
    cout << q.front() << endl;
    cout << q.back() << endl;
    cout << q.size() << endl;
    cout << q.empty();
    return 0;
}