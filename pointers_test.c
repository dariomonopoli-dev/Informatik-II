#include <stdio.h>
void swap(int &x, int &y)
{
    int temp = x;
    x = y;
    y = temp;
}
  
void wrong_swap (int x, int y){
    int temp = x;
    x = y;
    y = temp;
}
int main()
{
    int a = 19;
    int b = 91;
    wrong_swap(a,b);
    swap(a,b);
    printf("%d", a);


    return 0;
}