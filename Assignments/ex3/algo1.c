#include <stdio.h>

int algo1(int A[], int n, int k)
{
    int sum, i, j, swp, maxi;
    sum = 0;
    for (i = 0; i<=k-1; i++)
    {
        maxi = i;
        for (j = i-1; j++<=n-1; j++)
        {
            if (A[j] > A[maxi]){
                maxi = j;
            }
        }
        sum+= A[maxi]; //sums the max every time
        swp = A[i];
        A[i] = A[maxi];
        A[maxi] = swp;
    }

    return sum;
    



}
int main()
{
    int A[]={1,2,3,4,5,6};
    int n = 6;
    int k = 5;
    int x = algo1(A,n,k);
    printf("%d", x);



    return 0;
}