#include <stdio.h>

int isleap(int y)    //判断是不是闰年
{
    if((y%4==0 )&& (y%100!=0) ||( y%400==0))
    return 1;
    else
    return 0;
}

int main()
{
    int y,m,d;  //年月日
    int year=0;
    int passDay=0;  //过去的天数
    int remainDay;  //剩下的天数
    int mon[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};  //闰年在2月比平年多上一天，闰年：29天；
    printf("请输入一个日期：(格式是- -)");
    scanf("%d-%d-%d",&y,&m,&d);
    if(isleap(y))   //判断是不是闰年
    {
        mon[2]=29;
        year=366;
    }
    else
    year=365;
    for(int i=0;i<m;i++)
    {
        passDay=passDay+mon[i];
    }
    passDay=passDay+d;
    remainDay=year-passDay;
    printf("剩余的天数为%d",remainDay);

}