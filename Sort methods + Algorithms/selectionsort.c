#include <stdio.h>
void selection_sort(int a[], int length){
    for (int i = 0; i < length -1; i++){
        int k = i;
        for (int j = i+1; j<length; j++) {
            if (a[j] < a[k])
            {
                k=j;
            }

            
            
        }
        int temp = a[i];
            a[i] = a[k];
            a[k] = temp;
        
    }

}
int main() {
    int a[] = {5,9,7,6,4,0,2,3,8,1};
    int length = 10;
    selection_sort(a, length);
    for (int i = 0; i < 10; i++)
        { printf("a[%d] = %d\n", i, a[i]);
        }


    return 0;
}


