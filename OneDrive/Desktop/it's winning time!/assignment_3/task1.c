#include <stdio.h>
int whatDoesItDo(int A[], int n, int k)
{
    int current;
    int result = -1000;
    for (int i = 0; i < n; i++)
    {
        current = 0;
        for (int j = i; j < n; j+=k)
        {
            current+= A[j];
        }
        if (current > result)
        {
            result = current;
        }
    }
    return result;
}
int main()
{
    int A[] = {1,3,5,4,2,6,8};
    int n = sizeof(A)/sizeof(A[0]);
    int k = 3;
    int result = whatDoesItDo(A,n,k);
    printf("%d", result);



    return 0;
}