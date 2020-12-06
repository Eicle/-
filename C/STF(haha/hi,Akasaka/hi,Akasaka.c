#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

#define T double
T c(T x,T y,T r){return sqrt(x*x+y*y)-r;}
T u(T x,T y,T t){return x*cos(t)+y*sin(t);}
T v(T x,T y,T t){return y*cos(t)-x*sin(t);}
T fa(T x,T y){return fmin(c(x,y,0.5),c(x*0.47+0.15,y+0.25,0.3));}
T no(T x,T y){return c(x*1.2+0.97,y+0.25,0.2);}
T nh(T x,T y){return fmin(c(x+0.9,y+0.25,0.03),c(x+0.75,y+0.25,0.03));}
T ea(T x,T y){return fmin(c(x*1.7+0.3,y+0.7,0.15),c(u(x,y,0.25)*1.7,v(x,y,0.25)+0.65,0.15));}
T ey(T x,T y){return fmin(c(x+0.4,y+0.35,0.1),c(x+0.15,y+0.35,0.1));}
T pu(T x,T y){return fmin(c(x+0.38,y+0.33,0.03),c(x+0.13,y+0.33,0.03));}
T fr(T x,T y){return c(x*1.1-0.3,y+0.1,0.15);}
T mo(T x,T y){return fmax(c(x+0.15,y-0.05,0.2),-c(x+0.15,y,0.25));}
T o(T x,T y,T(*f)(T,T),T i){T r=f(x,y);return fabs(r)<0.02?(atan2(f(x,y+1e-3)-r,f(x+1e-3,y)-r)+0.3)*1.273+6.5:r<0?i:0;}
T s(T x,T y,T(*f)(T,T),T i){return f(x,y)<0?i:0;}
T f(T x,T y){return o(x,y,no,1)?fmax(o(x,y,no,1),s(x,y,nh,12)):fmax(o(x,y,fa,1),fmax(o(x,y,ey,11),fmax(o(x,y,ea,1),fmax(o(x,y,mo,1),fmax(s(x,y,fr,13),s(x,y,pu,12))))));}

void delay(int seconds)
 
{
 
   clock_t start = clock();
 
   clock_t lay = (clock_t)seconds * CLOCKS_PER_SEC;
 
   while ((clock()-start) < lay)
 
     ;
 
}

void full_screen()
{   
    HWND hwnd = GetForegroundWindow();
    int cx = GetSystemMetrics(SM_CXSCREEN);            /* ��Ļ��� ���� */
    int cy = GetSystemMetrics(SM_CYSCREEN);            /* ��Ļ�߶� ���� */

    LONG l_WinStyle = GetWindowLong(hwnd,GWL_STYLE);   /* ��ȡ������Ϣ */
    /* ���ô�����Ϣ ��� ȡ�����������߿� */
    SetWindowLong(hwnd,GWL_STYLE,(l_WinStyle | WS_POPUP | WS_MAXIMIZE) & ~WS_CAPTION & ~WS_THICKFRAME & ~WS_BORDER);

    SetWindowPos(hwnd, HWND_TOP, 0, 0, cx, cy, 0);
}

int main(void)
{
    int i;
    char arr[10], stop[]="STOP", stop2[]="\"STOP\"", cha;

    start:
    printf("���yo~С����~\n");
    delay(1);
    printf("��...\n");
    delay(2);
    printf("զ����ȫ�������У�����ȫ��Ŷ~�Ե�һ���ӣ����ڵ�����\n");
    delay(2);
    full_screen();
    delay(1);
    system("CLS");
    printf("ȫ���˰ɣ�\n");
    delay(1);
    printf("ȫ���˸��㻭ͷ��\n");
    delay(2);
    system("CLS");


    for(T y=-1,s=2;y<0.6;y+=0.05/s,putchar('\n'))for(T x=-1;x<0.6;x+=0.025/s)putchar(" .|/=\\|/=\\| @!"[(int)f(u(x,y,0.3),v(x,y,0.3))]);

    delay(4);

    system("CLS"); 

    printf("�ÿ�����ʵ�����Ϊ�˸��㻭һֻ���������������APEX�����鸴��\n");
    delay(2);
    for ( i = 1999; i > 0; i--)
    {
        printf("�����ģ��������ˣ�����");
    }
    delay(2);
    system("CLS"); 
    printf("�²۽����ǡ�\n");
    delay(1);
    system("CLS"); 
    printf("�ðɣ�����͵������~����\"STOP\"����������~\n���룺");
    stop:
    gets(arr);

    if (strcmp(arr, stop) == 0)
    {
        printf("��û�д�����Ŷ��������\"STOP\"����������\n���룺");
        goto stop;
    }
    else if (strcmp(arr, stop2) == 0)
    {
        printf("�����Ҫѡ�񲻵ò���Ҫ�Ĳ��˳��𣿣������� Y �� N \n���룺");
        scanf("%c", &cha);
        if (cha == 'N')
        {
            printf("�װ�~");
            delay(3);
            exit(0);
        }
        else if (cha == 'Y')
        {
            printf("���˳����ǾͲ��˳�8��\n");
            printf("�ص���ǰing~");
            delay(1);
            system("CLS");
            delay(1);

            goto start;
        }
        else
        {
            printf("��������ɶ�����߰���Ķ���Ŷ���Ǿ�Ĭ�ϲ��˳�8!\n����\"STOP\"����������~\n���룺");
            goto stop;
        }
        

    }
    else
    {
        printf("��������ɶ�����߰���Ķ���Ŷ��������\"STOP\"����������\n���룺");
        goto stop;
    }
    
    
    getchar();
    }