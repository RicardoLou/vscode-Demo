#include<stdio.h>
#include<iostream>
#include<string.h>
#define MAXCHAR  30
using namespace std;
struct  str{
   char  vec[MAXCHAR];
   int  len;
};
//找最长公共子串算法
void maxcomstr(struct str *s,struct str *t){
  int index=0,maxlen=0,i=0,j,k,leng;
  while (i < s->len){
    j = 0;
  while (j < t->len){
    if (s -> vec[i] == t -> vec[j]){
      leng = 1;
  for (k=1; (i + k < s->len) && (j + k < t->len) && s->vec[i+k] == t-> vec[j+k]; k++)
	 leng ++;
  if (leng > maxlen){
  index=i;//找到更大的公共子串的时候index就给到新的i
  maxlen = leng;//最大子串长度更新
}
  //j+=leng;//j继续更新到当前匹配的子串后
  j++;
}
else j++;//否则j就往后走继续进行匹配
}
i++;//i更新，进一步与j进行匹配
}
        printf("\n字符串 %s 和 %s 的最长公共子串: ", s->vec, t->vec);
        for (i = 0; i < maxlen; i++) {
            printf("%c", s->vec[index + i]);
        }
        printf("\n");
}

 
int main() { 
struct  str  *r,*r1;
r=new str; r1=new str;
cout<<"输入第一个字符串："<<endl;
scanf("%s",r->vec);
r->len=strlen(r->vec);
cout<<"输入第二个字符串："<<endl;
scanf("%s",r1->vec);
r1->len=strlen(r1->vec);
maxcomstr(r,r1);
return 0;
}
