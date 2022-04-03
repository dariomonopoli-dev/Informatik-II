#include <stdio.h>
#define MIN -999999

int main() {
	int A[] =  { 11, 3, -3, 2, 5};
    int length = sizeof(A)/sizeof(A[0]);
	int pos1 = -1, pos2=-1;
	int target = MIN;
	for (int i = 0; i<length; i++) {
        if (A[i] > target){
        target = A[i];
        pos1 = i;
        }
    }
    target = MIN;
    for (int i = 0; i<length; i++){
        if (pos1!=i && A[i]> target){
            target = A[i];
            pos2 = i;
        }
    }
printf("%d", A[pos2]);
return 0;
}
