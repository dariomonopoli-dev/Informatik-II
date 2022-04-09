#include <stdio.h>
int LomutoPartition(int A[], int l, int r)
{
    int pivot = A[r];
    int i = l-1;
    for (int j = l; j<= r- 1; j++)
    {
        if (A[j] <= pivot)
        {
            i+=1;
            int temp = A[i];
            A[i] = A[j];
            A[j] = temp;
        }
    }
    int temp2 = A[i+1];
    A[i+1] = A[r];
    A[r] = temp2; //the new pivot is being set
    return (i+1); //new pivot m called in LomutoPartition
}


void QuickSort_Lomuto(int A[], int l, int r)
{
    if (l < r)
    {
        int m = LomutoPartition(A, l, r);
        QuickSort_Lomuto(A, l, m-1);
        QuickSort_Lomuto(A, m+1, r);
    }
}
void printArray(int A[], int n)
{
    for (int i = 0; i<n; ++i)
    {
        printf("%d ", A[i]);
    }
}


int HoarePartition(int A[], int l, int r)
{
    int pivot = A[r];
    int i = l-1;
    int j = r + 1;
    while (1)
    {
        do
        {
            j--;
        } while (A[j] > pivot);
        

        do
        {
            i++;
        } while (A[i] < pivot);
       
        if (i < j)
        {
        
            int temp = A[i];
            A[i] = A[j];
            A[j] = temp;
        }
        else
        {
            return i;
        }
    }
    
}
void QuickSort_Hoare(int A[], int l, int r)
{
    if (l < r)
    {    
        int m = HoarePartition(A, l, r);
        QuickSort_Hoare(A, l, m - 1);
        QuickSort_Hoare(A, m, r);
    }
    
}


int main()
{
    int A[] = {11, 0, 9, 19, 8, 1, 5, 13, 18, 7};
    int n = sizeof(A) / sizeof(A[0]);
    printf("Unsorted Array: \n");
    printArray(A, n);
    printf("\n");
    QuickSort_Lomuto(A, 0, n-1);
    printf("Sorted Array (Lomuto Partition): \n");
    printArray(A, n);
    // printf("\nSorted Array (Hoare Partition): \n");
    // QuickSort_Hoare(A, 0, n-1);
    // printArray(A, n);

    return 0;
}