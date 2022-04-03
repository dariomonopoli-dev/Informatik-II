#include <stdio.h>
int binary_search_iterative(int a[], int length, int target) 
{
    int left = 0;
    int right = length-1;
    int middle = (right+left)/2;

    while (left <= right && a[middle]!=target)
    {
        if (a[middle] > target)
            right = middle - 1;

        else
            left = middle + 1;

        middle = (right+left)/2;


    }
    if (left <= right)
    return middle;
    else
    return -1;
    

}


int binary_search_recursively(int a[], int length, int target, int right, int left) 
{


    if (left <= right)
    {
        int middle = (right+left)/2;

        if (a[middle] == target)
            return middle;

        else if (a[middle] > target)
        return binary_search_recursively(a,length,target,middle+1,left);
    

        else
        return binary_search_recursively(a,length,target,right, middle+1);



    }
    return -1;
}

    



int main() 
{
    int a[] = {10,20,30,40,50};
    int length = 5;
    int target = 20;
    int x = binary_search_iterative(a, length, target);
    printf("The result is %d\n", x);

    int left = 0;
    int right = length-1;
    int y = binary_search_recursively(a,length, target, right,left);
    printf("The result is %d\n", y);

    
    return 0;
}

