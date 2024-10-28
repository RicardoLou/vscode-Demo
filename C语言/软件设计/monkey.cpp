#include<iostream>
using namespace std;
int main() {
    int t = 1;
    for(int i = 1; i < 10; i ++) {
        t = t + 1 << 1;
    }
    cout << t;
    return 0;
}