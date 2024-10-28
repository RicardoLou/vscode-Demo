#include <stdio.h>
#include <stdlib.h>
#define stack_init_size 100
#define stackincrement 10
typedef struct sqstack
{
    int *base;
    int *top;
    int stacksize;

} sqstack;
int StackInit(sqstack *s)
{
    s->base = (int *)malloc(stack_init_size * sizeof(int));
    if (!s->base)
        return 0;
    s->top = s->base;
    s->stacksize = stack_init_size;
    return 1;
}
int Push(sqstack *s, int e)
{
    //如果栈满的情况
    if (s->top - s->base >= s->stacksize)
    {
        s->base = (int *)realloc(s->base, (s->stacksize + stackincrement) * sizeof(int));
        if (!s->base)
            return 0;
        s->top = s->base + s->stacksize;
        s->stacksize += stackincrement;
    }
    *(s->top++) = e;
    return e;
}
int Pop(sqstack *s, int e)
{
    //如果栈空的情况
    if (s->top == s->base)
        return 0;
    e = *(--(s -> top));
    return e;
}
int stackempty(sqstack *s)
{
    if (s->top == s->base)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int conversion(sqstack *s)
{
    int n, e = 0, flag = 10;
    printf(" ----------------------------------------\n");
    printf("|                                       |\n");
    printf("|   学号:22106080901418 姓名:刘曹锋       |\n");
    printf("|                                       |\n");
    printf("|          版权所有请勿盗版               |\n");
    printf("|                                       |\n");
    printf(" ----------------------------------------\n");
    printf("输入要转化的十进制数：\n");
    scanf("%d", &n);
    printf("要转化为多少进制:2进制、8进制、16进制填数字!\n");
    scanf("%d", &flag);
    printf("将十进制数%d转化为%d进制是:\n", n, flag);
    while (n){
        Push(s, n % flag);
        n = n / flag;
    }
    while (!stackempty(s)){
        e = Pop(s, e); switch (e){
        case 10:
            printf("A");
            break;
        case 11:
            printf("B");
            break;
        case 12:
            printf("C");
            break;
        case 13:
            printf("D");
            break;
        case 14:
            printf("E");
            break;
        case 15:
            printf("F");
            break;
        default:
            printf("%d", e);
        }
    }
    printf("\n");
    return 0;}
int main(){
    sqstack s;
    StackInit(&s);
    conversion(&s);
    return 0;
}
