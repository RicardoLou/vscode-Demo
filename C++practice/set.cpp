#include<bits/stdc++.h>

using namespace std;

int main() {
    set<int> s;
    //set只会传进去一个值，不会有重复
    s.insert(1);
    s.insert(2);
    s.insert(2);
    s.insert(3);
    s.erase(2);//删除这个元素
    if(s.count(1))
        cout << "Yes" << endl;
    s.clear();
    cout << s.size() << endl;
    s.insert(3);
    for(int a : s)
        cout << a << endl;
    return 0;
}