#include <stdio.h>

int enMonths[2][12] = {{31,28,31,30,31,30,31,31,30,31,30}, {31,29,31,30,31,30,31,31,30,31,30}};//二维数组分别为平年和闰年各月份天数

int LeapYear(year)  //判断是否为闰年
{
    int leap = 0;
    if ((year%4 == 0) && (year%100 != 0) || (year%400 == 0))
        leap = 1;
   
    return leap;
}

int CalcDays(int year, int month, int day)  //计算从今天到元旦共多少天
{
    int i, daysBefore = 0;   
    short index = LeapYear(year);
    for(i=0; i<(month-1); i++)
    {
        daysBefore += enMonths[index][i];
    }
   
    return (daysBefore + day);
}

int FirstFriday(int year, int month, int day)
{
    short index = LeapYear(year);
    int days = 0, monthFri = 0;
    days = CalcDays(year, month, day);  //从今天到元旦共多少天
    int FirstFri = (days % 7);          //得出1月第一个周五是几号

    while(FirstFri == 0)
    {
        FirstFri = 7;                   //说明第一个周五为1月7日
    }
    for(int NowMonth=0; NowMonth<=12; ++NowMonth)   //遍历月份
    {   
        for(monthFri = FirstFri; monthFri <= enMonths[index][NowMonth-1]; )
        {
            printf("%d-%d-%d\n", year, NowMonth, monthFri);
            monthFri += 7;
        }
        FirstFri = monthFri - enMonths[index][NowMonth-1];  //将差值赋给下个月第一个周五
    }      
}


int main(void)
{
    int leap, year = 0, month = 0, day = 0; //定义闰年标志、用户输入的年月日

    printf("Please input year: ");
    scanf("%d", &year);
    printf("Please input month: ");
    scanf("%d", &month);
    printf("Please input day: ");
    scanf("%d", &day);
    printf("\n您所输入年份的全部星期五日期为：\n");
    FirstFriday(year, month, day);
}