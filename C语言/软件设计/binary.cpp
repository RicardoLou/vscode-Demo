#include<iostream>
#include<algorithm>
using namespace std;
int main(){
    int a[10];
    for(int i = 0; i < 10; i ++)
        a[i] = i + 1;
    int x;
    cin >> x;
    int l = 0, r = 9;
    while(l < r) {
        int mid = (l + r) / 2;
        if(a[mid] < x) l = mid + 1;
        else r = mid;
    }
    if(a[l] != x) cout << "-1";
    else cout << l + 1;
    return 0;
}