#include <stdio.h>
#include <stdlib.h>
#define TYPE struct stu
#define LEN sizeof(struct stu)

struct stu
{
    int num;
    char name[15];
    struct stu *next;
};

TYPE *create(int n)
{
    struct stu *head = (TYPE *)malloc(LEN);
    head->next = NULL;
    struct stu *pf, *pb;
    int i;

    for (i = 0; i < n; i++)
    {
        pb = (TYPE *)malloc(LEN);
        printf("input Number and Name\n");
        scanf("%d %s", &pb->num, pb->name);
        if (i == 0)
            pf = head->next = pb; // 设置头节点的next指向第一个节点
        else
            pf->next = pb;
        pb->next = NULL;
        pf = pb;
    }
    return head; // 返回头节点
}

TYPE *delet(TYPE *head, int num)
{
    TYPE *pf, *pb;
    if (head->next == NULL)
    {
        printf("\nempty list!\n");
        goto end;
    }
    pb = head->next; // 从第一个节点开始遍历

    // 遍历找到num所在的位置
    while (pb->num != num && pb->next != NULL)
    {
        pf = pb;
        pb = pb->next;
    }

    // 删除节点
    if (pb->num == num)
    {
        pf->next = pb->next;
        printf("The node is deleted\n");
        free(pb);
    }
    else
        printf("The node not been found!\n");

end:
    return head;
}

TYPE *insert(TYPE *head, TYPE *pi)
{
    TYPE *pb, *pf;
    pb = head->next; // 从第一个节点开始遍历

    if (head->next == NULL)
    {
        head->next = pi;
        pi->next = NULL;
    }
    else
    {
        while ((pi->num > pb->num) && (pb->next != NULL))
        {
            pf = pb;
            pb = pb->next;
        }

        if (pi->num <= pb->num)
        {
            pf->next = pi;
            pi->next = pb;
        }
        else
        {
            pb->next = pi;
            pi->next = NULL;
        }
    }

    return head;
}

void print(TYPE *head)
{
    printf("Number\t\tName\n");
    TYPE *current = head->next; // 从第一个节点开始
    while (current != NULL)
    {
        printf("%d\t\t%s\n", current->num, current->name);
        current = current->next;
    }
}

int main(void)
{
    TYPE *head, *pnum;
    int n, num;

    printf("input number of node: ");
    scanf("%d", &n); /*输入所建链表的结点数*/
    head = create(n); /*建立链表并把头指针返回给head*/
    print(head);

    printf("Input the deleted number: ");
    scanf("%d", &num); /*输入待删结点的学号*/
    head = delet(head, num); /*删除一个结点*/
    print(head); /*输出链表*/

    printf("Input the inserted number and name: ");
    pnum = (TYPE *)malloc(LEN); /*分配一个结点的内存空间*/
    scanf("%d %s", &pnum->num, pnum->name); /*输入待插入结点的数据域值*/
    insert(head, pnum); /*插入pnum所指的结点*/
    print(head); /*再次调用print函数输出链表*/

    return 0;
}