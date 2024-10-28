#include <stdio.h>

int isLuckyNumber(int num) {
    int sum = 0;
    int temp = num;
    int count = 0;

    while (temp > 0) {
        count++;
        temp /= 10;
    }

    if (count % 2 != 0) {
        return 0; // 不是偶数位数，不是幸运数字
    }

    int halfCount = count / 2;
    temp = num;

    for (int i = 0; i < halfCount; i++) {
        sum += temp % 10;
        temp /= 10;
    }

    int reverseNum = 0;

    for (int i = halfCount; i < count; i++) {
        reverseNum = reverseNum + temp % 10;
        temp /= 10;
    }

    if (sum == reverseNum) {
        return 1; // 是幸运数字
    } else {
        return 0; // 不是幸运数字
    }
}

int main() {
    int count = 0;

    for (int i = 1; i <= 100000000; i++) {
        if (isLuckyNumber(i)) {
            count++;
        }
    }

    printf("从1至100000000之间共有%d个不同的幸运数字。\n", count);

    return 0;
}

