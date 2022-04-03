#include <stdio.h>
void SelectionSort2(int a[], int length){
    for (int i = length-1; i >=1; i--){
        int k = i;
        for (int j = i-1; j>=0; j--) {
            if (a[j] > a[k])
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
    int a[] = {2,7,6,4,0,9,5,3,8,1};
    int length = 10;
    SelectionSort2(a, length);
    for (int i = 0; i < 10; i++)
        printf("a[%d] = %d\n", i, a[i]);
        
        


    return 0;
}
