#include <stdio.h>

void Heapify(int A[], int i, int s)
{
    int middle = i;
    int left = 2*i;
    int right = 2*i + 1;
    if (left < s && A[left] > A[middle])
    {
        middle = left;
    }
    if (right < s && A[right] > A[middle])
    {
        middle = right;
    }
    if (i!=middle) //means the two element need to be switched because child is greater than parent
    {
        int temp = A[i];
        A[i] = A[middle];
        A[middle] = temp;
        Heapify(A,middle, s); //l'elemento che è andato sotto è un heap oppure devo fare un heap con quello?
    }

}
void BuildHeap(int A[], int n)
{
    for (int i = n / 2 - 1; i>=0; i--)
    {
        Heapify(A, i, n);
    }
}
void Heapsort(int A[], int n)
{
  int s = n;
  BuildHeap(A, n);
  for (int i = n-1; i > 0; i--) //non metto >=0 perchè dopo seno il programma switcha il primo elemento con se stèsso il che è inutile (costs)
  {
      int temp = A[i];
      A[i] = A[0];
      A[0] = temp;
      s--;
      Heapify(A, 0, s);
  }


}
void PrintArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
}
int main()
{
    int arr[] = {8,6,5,4,3,90,-1};
    int n = sizeof(arr) / sizeof(arr[0]);
    Heapsort(arr, n);
    PrintArray(arr, n);

    
}