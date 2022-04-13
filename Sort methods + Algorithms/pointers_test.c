#include <stdio.h>

  
void wrong_swap (int x, int y){
    int temp = x;
    x = y;
    y = temp;
}
int main()
{
    int a = 19;
    int b = 91;
    int* c  = 5;
    int* d;
    c = d;
    wrong_swap(a,b);
    printf("%d", a);


    return 0;
}