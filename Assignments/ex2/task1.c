#include <stdio.h>
int rec_fun2(int x, int y) {
    if  (x<=0)
    {
        y = y+ 5;
        return y;
    }
    else{
        int t1 = rec_fun2(x-1, y+2);
        int t2 = rec_fun2(x-2, y+3);
        return t1+ t2;
    }
        

    
}

int main()
{
    int x = rec_fun2(3, 0);
    printf("%d", x);
    return 0;
}