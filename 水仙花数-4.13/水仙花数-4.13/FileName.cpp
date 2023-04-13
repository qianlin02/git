//����narcissistic�ж�number�Ƿ�Ϊˮ�ɻ��������򷵻�1�����򷵻�0��
//����PrintN���ӡ������(m, n)�����е�ˮ�ɻ�����ÿ������ռһ�С���Ŀ��֤100��m��n��10000
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

/* ��Ĵ��뽫��Ƕ������ */
int narcissistic(int number)
{
    int sum = 0;
    int a = number;
    int count = 0;
    int b = 0;
    while (a)
    {
        count++;//�������
        a /= 10;

    }
    a = number;//a����һ���ı��ˣ�number�ǲ��ܸı��
    while (a)
    {
        b = a % 10;
        sum += pow(b, count);
        a /= 10;
    }
    if (sum == number)//  ��һ�γ����ڴ˴�������һ��while��a�õ���number
        return 1;
    else
        return 0;
}
void PrintN(int m, int n)
{
    int i = 0;
    for (i = m + 1; i < n; i++)//ע����Ŀ����m��n���������߽磩
    {
        if (narcissistic(i))
        {
            printf("%d\n", i);
        }

    }
}