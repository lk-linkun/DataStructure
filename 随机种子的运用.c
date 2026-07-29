#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand((unsigned int)time(NULL));    //随机种子

    int num=rand()%101; //随机数，我们要猜的数字

    printf("提示：数字范围在0~100，请你开始大胆猜测吧！\n");

    int number=0;
    int temp=0; //记录猜测的次数

    while(1)
    {
        printf("请输入你猜测的数字：");
        scanf("%d",&number);
        temp++;

        if(number>num)
        {
            printf("猜大啦，再往小猜猜：");
            continue;
        }

        else if(number<num)
        {
            printf("猜小啦，再往大猜猜：");
            continue;
        }

        else if(number==num)
        {
            printf("恭喜你！猜对啦，你用了%d次。",temp);
            break;
        }
    }

}