#include <stdio.h>
int Left(int i) {
    return 2*i+1;
}

int Right(int i) {
    return 2*i+2;
}

//min heap: ascending order
void Heapify(int A[], int i, int s) {
    int m = i;
    int l = Left(i);
    int r = Right(i);

    if (l < s && A[l] > A[m]) {
        m = l;
    }
    if (r < s && A[r] > A[m]) {
        m = r;
    }
    if (i != m) {
        int temp = A[i];
        A[i] = A[m];
        A[m] = temp;
        Heapify(A,m,s);
    }
}
//max heap: descending order
void Heapify2(int A[], int i, int s) {
    int m = i;
    int l = Left(i);
    int r = Right(i);

    if (l < s && A[l] < A[m]) {
        m = l;
    }
    if (r < s && A[r] < A[m]) {
        m = r;
    }
    if (i != m) {
        int temp = A[i];
        A[i] = A[m];
        A[m] = temp;
        Heapify(A,m,s);
    }
}

void BuildHeap(int A[], int n) {
    for (int i = (n/2); i >= 0; i--) {
        Heapify2(A,i,n);
    }
}

void HeapSort(int A[], int n) {
    int s = n;
    BuildHeap(A,n); // O(n)
    for (int i = n-1; i>0; i--) {
        int temp = A[i];
        A[i] = A[0];
        A[0] = temp;
        s--;
        Heapify2(A,0,s);
    }
    for (int i = 0; i<n; i++) {
        printf("%i ", A[i]);
    }
    printf("\n");
}

int main() {
    int A[] = {5,1,7,8,9,0,3};
    int n = 7;

    HeapSort(A,n);
    printf("\n");
}