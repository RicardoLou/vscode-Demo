#include<bits/stdc++.h>
using namespace std;

int n;
string s;
void makeTree(int left, int right) {
    int mid = left + (right - left) / 2;
    if(left < right) {
        makeTree(left, mid);
        makeTree(mid + 1, right);
    }
    int B = 0, I = 0;
    for(int i = left; i <= right; i ++) 
        if(s[i] == '0') B ++;
        else I ++;
        
    if(B && I) 
        cout << "F";
    else if (B) 
        cout << "B";
    else 
        cout << "I";
    
}

int main() {
    cin >> n;
    cin >> s;
    makeTree(0, (1 << n) - 1);
}