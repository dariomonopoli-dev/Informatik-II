#include <stdio.h>
//modified bubble sort: at each iteration of the outer loop the smallest element of the subarray is moved to the left.
void bubblesort_2(int a[], int length);
int main() 
{
    int a[10] = {1,3,24,9,0,2,-3,5,8,6};
    int length = 10;
    bubblesort_2(a, length);
    for (int i = 0; i < length; i++)
    printf("a[%d] = %d\n", i, a[i]);
    
    

    return 0;
}
void bubblesort_2(int a[], int length)
{
for (int i = 0; i < length-1; i++){
    for (int j = length-1; j > i; j--) //length - 1 because last element orders itself automatically
    {
        if (a[j] < a[j-1]){
            int temp = a[j-1];
            a[j-1] = a[j];
            a[j] = temp;
        }
        
    }
}

}