#include<bits/stdc++.h>


using namespace std;

int main() {
    priority_queue<int> pq1;
    pq1.push(1);
    pq1.push(2);
    pq1.push(3);
    cout << pq1.top() << endl;
    pq1.pop();
    cout << pq1.top() << endl;
    //小根堆
    priority_queue<int, vector<int>, greater<int> > q;
    q.push(3);
    q.push(2);
    q.push(1);
    //更改堆顶元素
    int a = q.top();
    q.pop();
    q.push(a + 1);
    cout << q.top() << endl;
}