#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
using namespace std;
#define MAXSIZE 100

typedef struct {
    char no[8];   //8位学号
    char name[20]; //姓名
    int grade;     //成绩
}Student;

typedef  struct {
  Student  *elem;     //指向数据元素的基地址
  int  length;       //线性表的当前长度                                                           
 }SqList;

//初始化
int InitList_Sq(SqList &L){    //构造一个空的顺序表L
    L.elem=new Student[MAXSIZE];   //为顺序表分配空间
    if(!L.elem) exit(0);       //存储分配失败
    L.length=0;					  //空表长度为0
    return 1;}

//插入
void input_Sq(SqList &L,int n){
    int i;
    for (i=0;i<n;i++){
    cout << "请输入第" << i + 1 << "个人的学号:";
    cin >> L.elem[i].no;
    cout << "请输入第" << i + 1 << "个人的姓名:";
    cin >> L.elem[i].name;
    cout << "请输入第" << i + 1 << "个人的成绩:";
    cin >> L.elem[i].grade;
}
  L.length=n;	
}
//输出
void output_Sq(SqList &L){
    int i;
    cout << "学号   姓名     成绩" << endl;
    for (i=0;i<L.length;i++) {
        cout << L.elem[i].no << "   ";
        cout << L.elem[i].name << "   ";
        cout << L.elem[i].grade << "    "<< endl;
    }
}

//通过序号访问
void GetElem(SqList L,int i)
{
  if (i<1||i>L.length) cout << "位置错误！" << endl;   
   //判断i值是否合理，若不合理，返回0
  else {
    cout << L.elem[i - 1].no << " "<< endl;
    cout << L.elem[i - 1].name << " " << endl;
    cout << L.elem[i - 1].grade << " " << endl;
  } //第i-1的单元存储着第i个数据
 
}

//根据姓名查找
void LocateELem(SqList L,char name[8])
{  
int i=0;
  for (;i< L.length;i++)
      if (strcmp(L.elem[i].name, name) == 0) 
	  {
        cout << L.elem[i].no << " " << L.elem[i].name << " " << L.elem[i].grade << endl;	  
		return;  
	  }
  if (i == L.length)
	  cout << "查无此人" << endl;
}

//在某个位置插入新的数据
void ListInsert_Sq(SqList &L,int i ,Student e){
	int j;
   if(i<1 || i>L.length+1) cout << "error" << endl;	         //i值不合法
   if(L.length==MAXSIZE) cout << "error" << endl;    //当前存储空间已满     
   for(j=L.length-1;j>=i-1;j--) 
       L.elem[j + 1] = L.elem[j];    //插入位置及之后的元素后移
    L.elem[i-1]=e;                     //将新元素e放入第i个位置
    ++ L.length;		     	//表长增1
}

//根据位置删除元素
void ListDelete_Sq(SqList &L,int i){
	int j;
   if((i < 1) || (i > L.length))  cout << "ERROR\n";	 //i值不合法
   for (j=i;j<=L.length-1;j++) 
	   L.elem[j] = L.elem[j + 1]; //被删除元素之后的元素前移    　     
       -- L.length;               	      //表长减1
  
}
int main() {
    int n,i,j,m;
    char name[8];
    SqList L;
    Student s;
    cout << "请输入学生人数：";
    cin >> n;
    if (!InitList_Sq(L))
      cout << "error!" << endl;
    input_Sq(L,n);
    output_Sq(L);
    cout << "请输入要查找的学生姓名：";
    cin >> name;
    LocateELem(L, name);
    cout << "请输入要访问的学生序号：";
    scanf("%d",&i);
    GetElem(L,i);
    cout << "请输入要插入的学生信息：";
    cin >> s.no >> s.name >> s.grade;
    cout << "请输入要插入的学生位置：";
    scanf("%d",&j);
    ListInsert_Sq(L, j, s);
    output_Sq(L);
    printf("请输入要删除的学生序号：");
    scanf("%d",&m);
    ListDelete_Sq(L, m);
    output_Sq(L);

    return 0;
}
