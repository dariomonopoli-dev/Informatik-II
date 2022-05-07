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

#include <stdio.h>
int shifted_binary_search(int a[], int length, int target, int right, int left) 
{

    if (left <= right)
    {
        int middle = (right+left)/2; //pivot element

        if (a[middle] == target) //if target is pivot (middle element) we don't have to search through array
            return middle;
        if (a[left] <= a[middle]) //left subarray is sorted
        {
            if (target >= a[left] && target<=a[ middle]) //target element is in left subarray
            {
                return shifted_binary_search(a,length,target,middle-1,left); //we search on the left (sorted) side of the array
            }
        return shifted_binary_search(a,length,target,right,middle+1);
        }
    
        else if (a[middle]<=a[right]){

            if (target >=a[middle] && target <=a[right]) //right subarray is sorted
            {
                return shifted_binary_search(a,length,target,right,middle+1);
        
            }
        return shifted_binary_search(a,length,target,middle-1, left);
        }



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

