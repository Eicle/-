#include <stdio.h>

int main(void)
{
    double num1, num2;
    int num3, num4, num5;
    char rec1, rec2;
    printf("������7�����ݣ�����Ϊ2ʵ����3������2�ַ�����");
    scanf("%lf %lf %d %d %d %c %c", &num1, &num2, &num3, &num4, &num5, &rec1, &rec2);
    printf("\n��7�����ݵ���Ϊ��7-%c 6-%c 5-%d 4-%d 3-%d 2-%.7lf 1-%.7lf", rec2, rec1, num5, num4, num3, num2, num1);

    return 0;
}