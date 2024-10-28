#include<iostream>
#include<vector>
#include<queue>

using namespace std;
#define x first
#define y second
vector<int> a;
bool cmp(int a, int b){
    return a > b;
}
int main() {
    a[0] = 1;
    printf("%d", a[0]);
}