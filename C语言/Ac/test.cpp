#include<iostream>
using namespace std;
int main() {
    int arr[10];
    memset(arr, 1, 10);
    fill(arr, arr + 10, 1);
    for(int i = 0; i < 10; i ++) {
        cout << arr[i] << endl;
    }
}