#include <stdio.h>

void Merge(int A[], int B[], int left, int right, int middle) {
    for (int i = left; i<=middle; i++) {
        B[i] = A[i]; //we copy the first half of the array in order to array B
    }
    for (int i = middle+1; i<=right; i++) {
        B[right+middle-i+1] = A[i]; //we copy the second half of the original array in reverse order into array B
    }
    int i = left;
    int j = right;
    for (int k = left; k<=right; k++) {
        if (B[i]<B[j]) {
            A[k] = B[i];
            i++;
        }
        else {
            A[k] = B[j];
            j--;
        }
    }
}

void MergeSort(int A[], int B[], int left, int right) {
    if (left<right) {
        int middle = (right+left)/2;
        MergeSort(A,B,left,middle);
        MergeSort(A,B,middle+1,right);
        Merge(A,B,left,right,middle);
    }
}

int main() {
    int A[] = {2,5,8,0,34,1,67};

    int left = 0;
    int right = sizeof(A)/sizeof(A[0])-1;
    int B[(right+5)];

    MergeSort(A,B,left,right);
    
    for (int i = 0; i<=right; i++) {
        printf("%d ", A[i]);
    }
    printf("\n");
}