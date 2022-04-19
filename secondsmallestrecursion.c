#include <stdio.h>
int get_second(int A[], int upper_limit, int smallest, int second_smallest)
{
    if (upper_limit==0)
    {
        if (A[0] < smallest)
        {
            return smallest;
        }
        if (A[0] < second_smallest && A[0]!=smallest)
        {
            return A[0];
        }
        else
        {
            return second_smallest;
        }
    }
    if (smallest < 1) //recursion has not started yet, smallest and second smallest have to be set
    {
        if (A[upper_limit] < A[upper_limit -1])
        {
            smallest = A[upper_limit];
            second_smallest = A[upper_limit -1];
        }
        else
        {
            smallest = A[upper_limit -1];
            second_smallest = A[upper_limit];
        }
    }
    else
    {
        if (A[upper_limit] < smallest)
        {
            second_smallest = smallest;
            smallest = A[upper_limit];
        }
        else if (A[upper_limit] < second_smallest && A[upper_limit]!=smallest)
        {
            second_smallest = A[upper_limit];
        }
    }
    return get_second(A, upper_limit -1, smallest, second_smallest);
}
int main()
{
    int A[] = {23,1,5,4,6,8};
    int length = sizeof(A)/sizeof(A[0]);
    int result = get_second(A, length -1, -1, -1);
    printf("The second smallest element in the array is: %d", result);



    return 0;
}