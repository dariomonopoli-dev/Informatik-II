#include <stdio.h>
int whatDoesItDo(int A[],int  n, int k){
    int result, current, i, j;  
    result = -1000;
    for (i = 0; i<n; i++)
    {
        current = 0;
        for (j = i; j< n; j+=k){
            current = current + A[j];
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
    int n = 7;
    int k = 3;
    int res = whatDoesItDo(A, n, k);
    printf("%d", res);




    return 0;
}

