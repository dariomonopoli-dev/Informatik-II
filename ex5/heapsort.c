#include <stdio.h>
int Left(int i)
{
    return 2 * i;
}
int Right(int i)
{
    return 2 * i + 1;
}
void Heapify(int A[], int i, int s)
{
    int m = i;
    int l = Left(i) ;
    int r = Right(i);
    if (l<s && A[l] > A[m])
    {
        m = l;
    }
    if (r<s && A[r] > A[m])
    {
        m = r;
    }
    if (i!=m)
    {
        int temp = A[i];
            A[i] = A[m];
            A[m] = temp;
            Heapify(A,m,s);
    }
}
void BuildHeap(int A[], int n)
{
    for (int i = n/2 - 1; i>=0; i--)
    {
        Heapify(A, i, n);
    }



}
void Heapsort(int A[], int n)
{
int s = n;
BuildHeap(A, n);
for (int i = n - 1; i>=1; i--)
{
    int swap = A[i];
            A[i] = A[0];
            A[0] = swap;
            s-=1;
        
            Heapify(A, 0, s);
}


}

void printArray(int A[], int n)
{
    for (int i = 0; i<n; i++)
    {
        printf("%d ", A[i]);
    }
}
int main()
{
    int A[] = {8,6,5,4,3,90,-1};
    int n = sizeof(A) / (sizeof(A[0]));
    Heapsort(A, n);
    printf("Sorted array is: \n");
    printArray(A, n);






    return 0;
}