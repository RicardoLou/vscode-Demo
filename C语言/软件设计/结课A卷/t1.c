#include<stdio.h>
#include<stdlib.h>
int main(){
    int a = 1;
    for(int i = 1; i < 10; i ++) {
        a = a + 1 << 1;
    }
    printf("%d",a);
}