#include <stdio.h>
void insertion_sort(int A[], int length);


int main()
{
    int a[] = {8,4,9,5,7,6,3,2};
    insertion_sort(a, 8);
    for (int i = 0; i < 8; i++)
         printf("a[%d] = %d\n", i, a[i]);
        
    return 0;
}
void insertion_sort(int a[], int length)
{
    for (int i = 1; i < length; i++) //from 2 to n (the first element can be ignored)
    {
        int key = a[i]; //i memorize the a[i] as key
        int j = i-1; //prendi in considerazione l'array da j a 2
        while (j >= 0 && key <  a[j])
        {
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = key;
    }


}
