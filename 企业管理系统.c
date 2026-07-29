#include <stdio.h>
#include <string.h>

//该企业管理系统包含的功能总共有：1、录入每个人的信息 2、显示所有人的工号 3、通过工号查找个人信息 4、修改个人信息

struct x{   //个人信息

    char name[20];   //名字
    int sex;         //性别  0：表示女生 1：表示男生
    char empid[20];   //工号
    char birth[20];  //出生日期
    char tel[20];    //电话
    char id[20];     //身份证号

}a[100];

int n;

void fuch1()    //输入个人信息
{
    printf("请问你要输入几个人的数据:");
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        printf("这是第%d个人的个人信息：\n",i+1);
        printf("请输入你的名字：");
        scanf("%s",a[i].name);
        printf("请输入你的性别（0是女生，1是男生。）:");
        scanf("%d",&a[i].sex);
        printf("请输入你工号：");
        scanf("%s",a[i].empid);
        printf("请输入你的出生日期：");
        scanf("%s",a[i].birth);
        printf("请输入你的电话号码：");
        scanf("%s",a[i].tel);
        printf("请输入你的身份证号：");
        scanf("%s",a[i].id);
        printf("\n");
    }
}

void fuch2()    //显示所有人的工号
{
    printf("所有人的工号如下所示：\n");
    for(int i=0;i<n;i++)
    {
        printf("%s \n",a[i].empid);
    }

}

void fuch3()    //通过工号查找个人信息
{
    char number[20];
    int flag; //标记是否找到员工，0=未找到，1=找到
    while(1) //循环，输错可以重复输入工号
    {
        flag = 0;
        printf("请输入你要查找的工号：");
        scanf("%s",number);
        
        //完整遍历所有员工
        for(int i=0;i<n;i++)
        {
            if(strcmp(a[i].empid,number) == 0)
            {
                printf("=====员工信息=====\n");
                printf("姓名是：%s\n",a[i].name);
                printf("性别是：%s\n",a[i].sex == 1 ? "男" : "女");
                printf("工号是：%s\n",a[i].empid);
                printf("出生日期是：%s\n",a[i].birth);
                printf("电话号码是：%s\n",a[i].tel);
                printf("身份证号码是：%s\n",a[i].id);
                flag = 1;
                break; //找到，跳出for循环
            }
        }
        //遍历完所有员工后判断是否找到
        if(flag == 0)
        {
            printf("未找到该员工的工号，请重新输入！\n\n");
        }
        else
        {
            break; //找到员工，退出while循环，回到主菜单
        }
    }
}

void fuch4()    //修改个人信息
{
    char number1[20];
    printf("请输入你要修改个人信息的工号：");
    scanf("%s",number1);
    for(int i=0;i<n;i++)
    {
        if(strcmp(a[i].empid,number1) == 0)
        {
            printf("这是第%d个人的个人信息：\n",i+1);
            printf("请输入你要修改的名字：");
            scanf("%s",a[i].name);
            printf("请输入你要修改的性别（0是女生，1是男生。）:");
            scanf("%d",&a[i].sex);
            printf("请输入你要修改工号：");
            scanf("%s",a[i].empid);
            printf("请输入你要修改的出生日期：");
            scanf("%s",a[i].birth);
            printf("请输入你要修改的电话号码：");
            scanf("%s",a[i].tel);
            printf("请输入你要修改的身份证号：");
            scanf("%s",a[i].id);
            break;
        }
    }  
}

int main()
{
    int number3;
    while(1)
    {
        printf("----------主菜单----------\n");
        printf(" 1、录入每个员工的个人信息\n");
        printf(" 2、显示每个员工的工号\n");
        printf(" 3、输入各员工对应的工号查找他的个人信息\n");
        printf(" 4、输入各员工对应的工号修改他的个人信息\n");
        printf(" 0、退出此系统\n");
        printf("请输入你1 2 3 4 0应用对应的功能:");
        scanf("%d",&number3);
        if(number3 == 0)    break;
        switch(number3)
        {
            case 1:
            fuch1();
            continue;
            case 2:
            fuch2();
            continue;
            case 3:
            fuch3();
            continue;
            case 4:
            fuch4();
            continue;
        }
    }
}