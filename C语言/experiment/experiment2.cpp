#include <stdio.h>
#include <stdlib.h>
#define NULL 0
#define TYPE struct stu
#define LEN sizeof (struct stu)
struct stu
{
    int num;
    char name[20];
    struct stu *next;
};
struct stu *head;
TYPE *creat(int n)    
{
    struct stu *pf,*pb;
    int i;
    for(i=0;i<2;i++)
    {
        pb=(TYPE*) malloc(LEN);
        printf("input Number and Name\n");
        scanf("%d%s",&pb->num,pb->name);
        if(i==0)
        pf = head = pb;
        else pf->next=pb;
        pb -> next = NULL;
        pf=pb;
    }
    return(head);
}
void print(TYPE * head)
{
    printf("Number\t\tName\n");
    while(head!=NULL)
    {
        printf("%d\t\t%s\n",head->num,head->name);
        head = head -> next;//
    }
}
int main(void)
{   creat(4);
    print(head); 
}
