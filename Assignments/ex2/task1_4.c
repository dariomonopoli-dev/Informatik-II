#include <stdio.h>
void rec_fun3a(int n)
{
    if (n==0) {
        return ;
    }
    printf("%d",n);
    rec_fun3b(n-2);
    printf("%d", n);
}
void rec_fun3b(int n)
{
    if (n==0) {
        return ;
    }
    printf("%d",n);
    rec_fun3a(n+1);
    printf("%d", n);
}

int main()
{
    rec_fun3a(5);

}