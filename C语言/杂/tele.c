#include<stdio.h>  
#include<stdlib.h>  
#include<string.h>

typedef struct chsystem
{
    char name[15];  //姓名  
    char tel[20];    //手机  
    char email[20];  //邮箱 
    char adrr[15];    //地址
}cs;               //通讯录结构体 

typedef struct pcs
{
    cs chat;
    pcs* next;
}*ptcs;   //通讯录节点  
ptcs head = (ptcs)malloc(sizeof(pcs));

/*int login()  //登录验证
{
    char key[20], ch;
    int flag = 0;
    printf("**********************欢迎登录通讯录管理系统***********\n\n");
    printf("**********************请输入密码***********************\n\n");
    printf("**********************密码:");
    scanf("%s", key);
    printf("\n");
    if (strcmp(key, "xuehao") == 0)
    {
        flag = 1;
        ch = getchar();
        printf("**********************登录成功*************************\n\n");
        printf("**********************按任意键进入操作界面*************\n");
        ch = getchar();
        return 1;
    }
    else
    {
        do
        {
            printf("**********************密码错误,登录失败,请重新登录*****\n\n");
            printf("**********************密码:");
            scanf("%s", key);
            printf("\n");
            if (strcmp(key, "xuehao") == 0)
            {
                flag = 1;
                ch = getchar();
                printf("**********************登录成功*************************\n\n");
                printf("**********************按任意键进入操作界面 *************\n");
                ch = getchar();
            }
        } while (flag == 0);
    }
    return 0;
}*/

int menu_select()  //功能选择框  
{
    char c;
    do
    {
        system("cls");
        printf("\n\t**********通讯录管理系统**********\n");
        printf("\t┌----------------------------------------------┐\n");
        printf("\t│        1.添加联系人           │\n");
        printf("\t│        2.查询联系人           │\n");
        printf("\t│        3.删除联系人           │\n");
        printf("\t│        4.输出联系人列表       │\n");
        printf("\t│        5.排序                 │\n");
        printf("\t│        6.写入文件             │\n");
        printf("\t│        7.读取文件             │\n");
        printf("\t│        8.修改                 │\n");
        printf("\t│        0.退出                 │\n");
        printf("\t└--------------------------------------------- ┘\n");
        printf("\t请您选择(0-8):");
        c = getchar();
    } while (c < '0' || c > '8');  //检查输入是否符合规范  
    return(c - '0');
}

int cala(char* p)  //计算字符串长度  
{
    int i, n = 0;
    for (i = 0; p[i] != '\0'; i++) n++;
    return n;
}

int Addpeo()  //添加联系人  
{
    int t, n, a;
    char flag = 'y';
    ptcs p = head, q;
    while (p->next) p = p->next;
    while (flag != 'n' && flag != 'N')
    {
        q = (ptcs)malloc(sizeof(pcs));
        p->next = q;
        p = q;
        q->next = NULL;
        printf("\n\t请输入:\n");
        printf("\t姓名:");  //输入姓名  
        scanf("\t%s", q->chat.name);
        printf("\t手机号码:");  //输入手机号  
        scanf("\t%s", q->chat.tel);
        do
        {
            n = 0;
            if (cala(q->chat.tel) != 11)
            {
                n = 1;
                printf("\t您输入的手机号码格式不存在,请重新输入:");
                scanf("\t%s", q->chat.tel);
            }
            else
            {
                for (t = 0; t < 11; t++)
                {
                    if (q->chat.tel[t] < '0' || q->chat.tel[t] > '9')
                    {
                        n = 1;
                        printf("\t您输入的手机号码格式不合理,请重新输入:");
                        scanf("\t%s", q->chat.tel);
                        break;
                    }
                }
            }
        } while (n);
       
        printf("\t电子邮箱:");  //输入邮箱  
        scanf("\t%s", q->chat.email);
        do
        {
            a = 0;
            for (t = 0; q->chat.email[t] != '\0'; t++)
            {
                if (q->chat.email[t] == '@')
                    a++;
            }
            if (a != 1)
            {
                printf("\t输入的邮箱不合理，请重新输入:");
                scanf("\t%s", q->chat.email);
            }
        } while (a != 1);
        printf("\t地址:"); //输入地址
        scanf("\t%s", q->chat.adrr);
        printf("\n\t是否继续添加?(Y/N)");
        scanf("\t%c", &flag);
    }
    return 0;
}

int watch_over()  //查询联系人  
{
    system("cls");
    int m, n;
    char flag = 'y';
    ptcs p = head->next;
    while (flag != 'n' && flag != 'N')
    {
        printf("\n\t*************查询方式*************\n");
        printf("\t┌-----------------------------------------------┐\n");
        printf("\t│          1.查找姓名           │\n");
        printf("\t│          2.查找手机号         │\n");
        printf("\t│          3.返回               │\n");
        printf("\t└-----------------------------------------------┘\n");
        printf("\n\t请选择查询方式:");
        scanf("\t%d", &m);  //选择查询方式  
        do
        {
            n = 0;
            if (m != 1 && m != 2 && m != 3)
            {
                n = 1;
                printf("\t您输入的查询方式不存在,请重新输入:");
                scanf("\t%d", &m);  //选择查询方式  
            }
        } while (n);
        if (!p)
        {
            printf("\t该通讯录为空!\n");
            return 0;
        }
        if (1 == m)
        {
            char nm[15];
            p = head->next;
            printf("\t请输入您要查询的联系人:");
            scanf("\t%s", nm);
            while (p != NULL && strcmp(p->chat.name, nm) != 0)  p = p->next;
            if (!p)
            {
                printf("\t您要查询的联系人不存在!\n");
                printf("\t是否继续查询?(Y/N)");
                scanf("\t%c", &flag);
                return 0;
            }
            printf("\t手机号码:%s\n", p->chat.tel);
            printf("\t电子邮箱:%s\n", p->chat.email);
            printf("\t地址:%s\n", p->chat.adrr);
        }
        if (2 == m)
        {
            char te[20];
            p = head->next;
            printf("\t请输入您要查询的手机号码:");
            scanf("\t%s", te);
            while (p != NULL && strcmp(p->chat.tel, te) != 0) p = p->next;
            if (!p)
            {
                printf("\t您要查询的联系人不存在!\n");
                printf("\t是否继续查询?(Y/N)");
                scanf("\t%c", &flag);
                return 0;
            }
            printf("\t姓名:%s\n", p->chat.name);
            printf("\t电子邮箱:%s\n", p->chat.email);
            printf("\t地址:%s\n", p->chat.adrr);
        }
        if (3 == m) return 0;
        printf("\t是否继续查询?(Y/N)");
        scanf("\t%c", &flag);
    }
    return 0;
}

int Delete()  //删除个人信息  
{
    char nm[20];
    char flag = 'y';
    ptcs p = head->next, bh, pre;
    if (!p)
    {
        printf("\t该通讯录为空!\n");
        return 0;
    }
    while (flag != 'n' && flag != 'N')
    {
        p = head->next;
        printf("\t请输入您要删除的联系人姓名:");
        scanf("\t%s", nm);
        while (p != NULL && strcmp(p->chat.name, nm) != 0)
        {
            pre = p;
            p = p->next;
        }
        if (!p)
        {
            printf("\t该联系人不存在!\n");
            printf("\t是否继续删除?(Y/N)");
            scanf("\t%c", &flag);
            return 0;
        }
        bh = p->next;
        if (p == head->next) head->next = bh;
        else pre->next = bh;
        printf("\t该联系人已删除!\n");
        printf("\t是否继续删除?(Y/N)");
        scanf("\t%c", &flag);
    }
    return 0;
}

int display()//输出通讯录列表  
{
    ptcs p = head->next;
    if (!p)
    {
        printf("\t该通讯录为空!\n");
        return 0;
    }
    printf("\n\t****************************通讯录列表****************************\n");
    printf("\t姓名\t手机号码\t邮编号码\t电子邮箱\t地址\n");
    printf("\t------------------------------------------------------------------\n");
    while (p)
    {
        printf("\t%-8s%-16ss%-16s%s\n", p->chat.name, p->chat.tel, p->chat.email, p->chat.adrr);
        p = p->next;
        printf("\t------------------------------------------------------------------\n");
    }
    return 0;
}

int cacu(ptcs p)//计算链表的长度  
{
    int n = 0;
    while (p)
    {
        p = p->next;
        n++;
    }
    return n;
}

int arrange1()   //对通讯录按姓名进行排序,这里用冒泡法排序  
{
    int i, n;
    ptcs pre = head, p = head->next, k, q;
    if (!p)
    {
        printf("\t该通讯录为空!\n");
        return 0;
    }
    n = cacu(p);
    for (i = 0; i < n - 1; i++)
    {
        for (p = head->next, pre = head; p->next->next != NULL; pre = p, p = p->next);
        {
            k = p->next;
            q = k->next;
            if (strcmp(p->chat.name, k->chat.name) > 0)
            {
                pre->next = k;
                k->next = p;
                p->next = q;
                p = k;
            }
        }
    }
    display();
    return 0;
}

int arrange2()    //对通讯录按手机号进行排序,这里用冒泡法排序  
{
    int i, n;
    ptcs pre = head, p = head->next, k, q;
    if (!p)
    {
        printf("\t该通讯录为空!\n");
        return 0;
    }
    n = cacu(p);
    for (i = 0; i < n - 1; i++)
    {
        for (p = head->next, pre = head; p->next->next != NULL; pre = p, p = p->next);
        {
            k = p->next;
            q = k->next;
            if (strcmp(p->chat.tel, k->chat.tel) > 0)
            {
                pre->next = k;
                k->next = p;
                p->next = q;
                p = k;
            }
        }
    }
    display();
    return 0;
}

int arrange()  //按姓名或手机号方式排序
{
    system("cls");
    int i, n;
    char flag = 'y';
    while (flag != 'n' && flag != 'N')
    {
        system("cls");
        printf("\n\t*************排序方式*************\n");
        printf("\t┌-----------------------------------------------┐\n");
        printf("\t│          1.姓名排序            │\n");
        printf("\t│          2.手机号排序          │\n");
        printf("\t│          3.返回                │\n");
        printf("\t└-----------------------------------------------┘\n");
        printf("\n\t请选择排序方式:");
        scanf("\t%d", &i);   //选择排序方式 
        do
        {
            n = 0;
            if (i != 1 && i != 2 && i != 3)
            {
                n = 1;
                printf("\t您输入的查询方式不存在,请重新输入:");
                scanf("\t%d", &i);   //选择查询方式  
            }
        } while (n);
        if (i == 1)
        {
            arrange1();
        }
        if (i == 2)
        {
            arrange2();
        }
        if (i == 3)
        {
            return 0;
        }
        printf("\t是否更换排序方式?(Y/N)");
        scanf("\t%c", &flag);
    }
    return 0;
}

int write()   //将数据写入文件
{
    ptcs p = head->next;
    FILE* fp;
    char filename[30];
    if (!p)
    {
        printf("\t该通讯录为空!");
        return 0;
    }
    printf("\t写入到文件!\n");
    printf("\t请输入所写入的文件名:");
    scanf("\t%s", filename);
    if ((fp = fopen(filename, "a+")) == NULL)
    {
        printf("\t无法打开文件!\n");
        system("pause");
        return 0;
    }
    fprintf(fp, "姓名\t手机号码\t电子邮箱\\t地址\n");
    while (p)
    {
        fprintf(fp, "%-8s%-16s%-16s%s\n", p->chat.name, p->chat.tel, p->chat.email, p->chat.adrr);
        p = p->next;
    }
    fclose(fp);           //关闭文件     
    printf("\t写入成功!\n");
    return 0;
}

int read()  //读取文件  
{
    char str[100]; char filename[30];
    FILE* fp;
    printf("\t读取文件!\n");
    printf("\t请输入读取的文件名:");
    scanf("\t%s", filename);
    if ((fp = fopen(filename, "a+")) == NULL)
    {
        printf("\t无法打开文件!\n");
        system("pause");
        return 0;
    }
    while ((fgets(str, 100, fp)) != NULL)
    {
        printf("\t%s", str);
    }
    return 0;
}
int change(ptcs p)//修改手机号码
{
    int i;
    scanf("\t%s", p->chat.tel);
    while (1)
    {
        if (strlen(p->chat.tel) != 11)
        {
            printf("输入的手机号码有误，请重新输入：");
            scanf("\t%s", p->chat.tel);
        }
        else
        {
            for (i = 0; i < 11; i++)

                if (p->chat.tel[i] < '0' && p->chat.tel[i] < '9')
                {
                    printf("输入的不是0-9之间的电话号码数字\n");
                    printf("请重新输入电话号码：");
                    scanf("\t%s", p->chat.tel);
                    break;
                }
        }
    }
    printf("手机号码修改成功！！！\n");
    return 0;
}

int main()
{
   // struct pcs* m;
  //  head = (struct pcs*)malloc(sizeof(struct pcs));//动态分配内存
   head->next = NULL;
  // login();
    system("cls");
    printf("\n\t**********通讯录管理系统**********\n");
    printf("\t┌----------------------------------------------┐\n");
    printf("\t│        1.添加联系人           │\n");
    printf("\t│        2.查询联系人           │\n");
    printf("\t│        3.删除联系人           │\n");
    printf("\t│        4.输出联系人列表       │\n");
    printf("\t│        5.排序                 │\n");
    printf("\t│        6.写入文件             │\n");
    printf("\t│        7.读取文件             │\n");
    printf("\t│        8.修改                 │\n");
    printf("\t│        0.退出                 │\n");
    printf("\t└---------------------------------------------┘\n");
    printf("\t请您选择(0-7):");
    printf("\n\t******************************通讯录列表******************************\n");
    printf("\t姓名\t手机号码\t邮编号码\t电子邮箱\t地址\n");
    head->next = NULL;
    for (;;)
    {
        switch (menu_select())
        {
        case 1:
            printf("\n\t添加记录到通讯录\n"); //添加记录  
            Addpeo();
            system("pause");
            break;
        case 2:
            printf("\n\t在通讯录中查找联系人\n");
            watch_over();
            system("pause");
            break;
        case 3:
            printf("\n\t从通讯录中删除联系人\n");
            Delete();
            system("pause");
            break;
        case 4:
            printf("\n\t输出通讯录列表\n");
            display();
            system("pause");
            break;
        case 5:
            printf("\n\t排序\n");
            arrange();
            system("pause");
            break;
        case 6:
            printf("\n\t写入文件\n");
            write();
            system("pause");
            break;
        case 7:
            printf("\n\t读取文件\n");
            read();
            system("pause");
            break;
        case 8:
            printf("\n\t修改联系人电话\n");
           // change(head);
            
            break;
        case 0:
            printf("\n\t谢谢使用，再见!\n");  //结束程序      
            printf("\n\t");
            system("pause");
            exit(0);
        }
    }
    return 0;
}