#include <stdio.h>
#include <stdlib.h>
typedef struct Polynode{
    int coef;
    int exp;
    struct Polynode *next;
}Polynode,*Polylist; 
  
Polylist PolyCreate(){
    Polynode *head;
    Polynode *rear, *s;
    int c,e;
    head=(Polynode*)malloc(sizeof(Polynode));
    rear=head; /* rear 始终指向单链表的尾，便于尾插法建表*/
    printf("输入一元多项式)以0为结束标记):\n");
    printf("要求:1.按幂从小到大输入各结点：\n");
    printf("       2.没有两个结点具有相同的幂：\n");
    printf("please input c and e:\n");
    scanf("%d%d",&c,&e);                   /*键入多项式的系数和指数项*/
 while(c!=0){                             /*若c=0，则代表多项式的输入结束*/
    s=(Polynode*)malloc(sizeof(Polynode)); /*申请新的结点*/
    s->coef=c;
    s->exp=e;
    rear->next=s; /*在当前表尾做插入*/
    rear=s;
    printf("please input c and e:again\n");
    scanf("%d%d",&c,&e); 
 }
    rear->next=NULL; /*将表的最后一个结点的next置NULL，以示表结束*/
    return head;
}
 
Polylist  PolyAdd(Polylist polya, Polylist polyb){
/*此函数用于将两个多项式相加，然后将和多项式存放在多项式polya中，并将多项式ployb删除*/
    Polynode  *p, *q, *pre, *temp;
    int sum;
    p=polya->next;   /*令 p和q分别指向polya和polyb多项式链表中的第一个结点*/
    q=polyb->next;        
    pre=polya;  /* r指向和多项式的尾结点*/
while (p!=NULL && q!=NULL) /*当两个多项式均未扫描结束时*/{ 
  if  (p->exp < q->exp){
   /*如果p指向的多项式项的指数小于q的指数，将p结点加入到和多项式中*/ 
    pre->next=p;  
    pre=p; 
    p=p->next;
}
  else if( p->exp == q->exp)  /*若指数相等，则相应的系数相加*/{  
    sum=p->coef + q->coef;
    if (sum != 0) { 
     p->coef=sum;
     pre->next=p; 
     pre=p;
     p=p->next;
     temp=q; 
     q=q->next; 
     free(temp);
    }
    else {  
     temp=p;
     p=p->next;
     free(temp); 
  /*若系数和为零，则删除结点p与q，并将指针指向下一个结点*/
     temp=q; 
     q=q->next;
     free(temp);
    }
   }
   else {  
    pre->next=q;
    pre=q; /*将q结点加入到和多项式中*/
    q = q->next; 
   }
 }
 if(p!=NULL)  /*多项式A中还有剩余，则将剩余的结点加入到和多项式中*/
    pre->next=p;
else      /*否则，将B中的结点加入到和多项式中*/
    pre->next=q;
return (polya);
}
 
void display(Polylist head){
    int first=1;
    head=head->next;
    while(head!=NULL){
        if (first){
            if(head->exp==1)
                printf("%dX",head->coef);
                    else if(head->exp==0)
                        printf("%d",head->coef);
                            else printf("%dX^%d",head->coef,head->exp);
            first=0;
    }
    else {
    if(head->exp==1)
        printf("+%dX",head->coef);
else if(head->exp==0) 
    printf("+%d",head->coef);
    else 
    printf("+%dX^%d",head->coef,head->exp);
}
    head=head->next;
}
printf("\n");
}
 
int main(){
    Polynode *poly1,*poly2,*poly3;
    poly1=PolyCreate();
    display(poly1);
    poly2=PolyCreate();
    display(poly2);
    poly3=PolyAdd(poly1,poly2);
    display(poly3);
    return 0;
}
