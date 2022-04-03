#include <stdio.h>
int main () {
    int lengthOfArray = 6;
    char array[] = {4,5,6,-7,2,17};
    int max = array[0];
    int second_max = array[1];
    
    for (int i=2; i<lengthOfArray; i++) {
        if (array[i] > max) {
            int temp = max;
            max = array[i];
            second_max = temp;
        }
        if (array[i] > second_max && array[i] < max){
            second_max = array[i];
        }
    }
    printf("%d", second_max);

    return 0;
}
