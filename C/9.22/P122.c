#include <stdio.h>

int main(void)
{
    int num1, num2, num4;
    double num3;
    printf("������4������");
    scanf("%d %d %lf %d", &num1, &num2, &num3, &num4);
    printf("\n������Ϊ��%016.7lf\n", (num1 % num2) * num3 + num4);

    return 0;

}