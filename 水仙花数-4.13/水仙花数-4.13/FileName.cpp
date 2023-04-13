//函数narcissistic判断number是否为水仙花数，是则返回1，否则返回0。
//函数PrintN则打印开区间(m, n)内所有的水仙花数，每个数字占一行。题目保证100≤m≤n≤10000
#include <stdio.h>
#include<math.h>
int narcissistic(int number);
void PrintN(int m, int n);

int main()
{
    int m, n;

    scanf("%d %d", &m, &n);
    if (narcissistic(m)) printf("%d is a narcissistic number\n", m);
    PrintN(m, n);
    if (narcissistic(n)) printf("%d is a narcissistic number\n", n);

    return 0;
}

/* 你的代码将被嵌在这里 */
int narcissistic(int number)
{
    int sum = 0;
    int a = number;
    int count = 0;
    int b = 0;
    while (a)
    {
        count++;//计算个数
        a /= 10;

    }
    a = number;//a在上一步改变了，number是不能改变的
    while (a)
    {
        b = a % 10;
        sum += pow(b, count);
        a /= 10;
    }
    if (sum == number)//  第一次出错在此处，在上一个while中a用的是number
        return 1;
    else
        return 0;
}
void PrintN(int m, int n)
{
    int i = 0;
    for (i = m + 1; i < n; i++)//注意题目是在m到n（不包括边界）
    {
        if (narcissistic(i))
        {
            printf("%d\n", i);
        }

    }
}