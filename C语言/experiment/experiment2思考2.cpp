#include <stdio.h>
#include <stdlib.h>
#define TYPE struct stu
#define LEN sizeof(struct stu)

struct stu{
    int num;
    char name[20];
    struct stu *next;
};
struct stu *head;
TYPE *creat(int n){
    struct stu *p;
    int i;
    head = NULL; // 初始化头指针为NULL
    for (i = 0; i < n; i++){
        p = (TYPE *)malloc(LEN);
        printf("input Number and Name\n");
        scanf("%d %s", &p->num, p->name);
        p->next = head; // 新节点的next指向当前头节点
        head = p;       // 更新头指针指向新节点
    }
    return head; // 返回新链表的头指针
}

void print(TYPE *head){
    printf("Number\t\tName\n");
    while (head != NULL){
        printf("%d\t\t%s\n", head->num, head->name);
        head = head->next;
    }
}

int main(void){
    creat(4);
    print(head);
}
