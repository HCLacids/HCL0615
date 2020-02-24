#include <stdio.h>
/*方法一
int main (){
    char c1 = 'C', c2 ='h', c3 = 'i', c4 = 'n', c5 = 'a';
    putchar (c1); putchar(c2); putchar(c3); putchar(c4);putchar(c5);putchar('\n');
    c1 += 4 ; 
    c2 += 4;
    c3 += 4;
    c4 += 4;
    c5 += 4;
    printf("%c%c%c%c%c\n",c1,c2,c3,c4,c5);
    return 0;
}*/
//方法二
int main (){
    char array[5]={'C','h','i','n','a'};
    for (int i = 0 ;i <= 5; i++){
        if (i == 5)
        {
            putchar('\n');
        }else
        {
            putchar(array[i]);
        }
    }
    for (int i = 0;i <= 5; i++){
        array[i] += 4;
    }
    char c[5]={'C','h','i','n','a'};
    for (int i = 0 ;i <= 5; i++){
        if (i == 5)
        {
            putchar('\n');
        }else
        {
        printf("%c",array[i]);
        }
    }
}