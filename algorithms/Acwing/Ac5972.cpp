#include<bits/stdc++.h>
using namespace std;
// str.substr(起始位置，长度)

int main() {
    string str;
    cin >> str;
    int dot = str.find('.');
    int e = str.find('e');
    int a = stoi(str.substr(0, dot));
    // b 可能比较大
    string b = str.substr(dot + 1, e - dot - 1);
    int d = stoi(str.substr(e + 1, str.length()));
    
    if(b != "0") str = str.substr(0, e);
    else str = to_string(a) + "."; // 只需要保留小数点前面和小数点即可
    
    if (a > 0) {
        while(d --) {
            if (dot + 1 >= str.length()) str += "0";
            swap(str[dot], str[dot ++]);
        }
    }
    if(str.back() == '.') str.pop_back();
    cout << str;
    return 0;
}