#include <stdio.h>

int main(void)
{
    char rec[10];
    int i;
    printf("\n������10���ַ���");
    gets(rec);
    printf("\n���ܽ��Ϊ��");
    printf("%d", rec[0]);
    for(i=1;i<10;i++)
        printf(", %d", rec[i]);

    return 0;



}