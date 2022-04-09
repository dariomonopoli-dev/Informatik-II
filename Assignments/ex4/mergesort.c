
#include <stdio.h>
void insertion_sort(int a[], int length)
{
    for (int i = 1; i < length; i++) //from 2 to n (the first element can be ignored)
    {
        int key = a[i]; //i memorize the a[i] as key
        int j = i-1; //prendi in considerazione l'array da j a 2
        while (j >= 0 && a[j] > key)
        {
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = key;
    }
}

void insertion_sort_reverse(int a[], int length)
{
    for (int i = 1; i < length; i++) //from 2 to n (the first element can be ignored)
    {
        int key = a[i]; //i memorize the a[i] as key
        int j = i-1; //prendi in considerazione l'array da j a 2
        while (j >= 0 && a[j] < key)
        {
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = key;
    }
}


int check_array(int a[], int n, int choice)
{
  int c, d = 1;
  int i = 0;
    while ((c == 1 || d == 1) && i < n - 1) {
    if (a[i] < a[i+1]){ //ascending
      d = 0;
      c = 1;
    }
    else if (a[i] > a[i + 1]){ // descending
      c = 0;
    }
    i++;
  }
  if (c == 1 ){
  return 0; 
  }
  else if (d == 1){
    return 2;
  }
  else
    return 1;
}

void print_array(int array[], int n) {
  int i;
  for (i=0; i<n; i++) {
    printf("%d ", array[i]);
  }
  printf("\n");
}

void merge(int a[], int l, int r, int m) {
  int i, j, k=0, b[1000];
  for (i = 0; i<=m; i++)
  {
      b[i] = a[i];
  }
  for (i = m+1; i<=r; i++)
  {
      b[r+m-i+1] = a[i];
  }
  i = l; j = r;
  for (k = l; k <= r; k++)
  {
      if (b[i] < b[j])
      {
          a[k] = b[i];
          i++;
      }
      else{
          a[k] = b[j];
          j--;
      }
  }
}

void merge_reverse(int a[], int l, int r, int m) {
  int i, j, k=0, b[1000];
  for (i = 0; i<=m; i++)
  {
      b[i] = a[i];
  }
  for (i = m+1; i<=r; i++)
  {
      b[r+m-i+1] = a[i];
  }
  i = l; j = r;
  for (k = l; k <= r; k++)
  {
      if (b[i] > b[j])
      {
          a[k] = b[i];
          i++;
      }
      else{
          a[k] = b[j];
          j--;
      }
  }

}

void mergeSort(int a[], int l, int r, int n) {
  int m;
  int threshold = 6;
  if (l < r) {


    if (r - l <= threshold){
        insertion_sort(a, n);
      }
    
    else{
    m = (l+r)/2;
    mergeSort(a, l, m, n);
    mergeSort(a, m+1, r, n);
    merge(a, l, r, m);
    }   
  }
}

void mergeSort_reverse(int a[], int l, int r, int n)
{
  int m;
  int number_of_executions = n;
  if (l < r) {
    while (number_of_executions >= 6){
      if (number_of_executions == 6){
        insertion_sort_reverse(a, n);
        break;
      }
    
    else{
    m = (l+r)/2;
    mergeSort_reverse(a, l, m , n);
    number_of_executions = number_of_executions / 2;
    mergeSort_reverse(a, m+1, r, n);
    number_of_executions = number_of_executions / 2;
    merge_reverse(a, l, r, m);
    }
    }
  }  
}

int main() {
    int n, array[] = {0,1,2,3,4,5};
    n = 6; //always change if size of array changes
    int choice = 1;
    int test1 = check_array(array, n, choice);
    int is_executable = 0;

    if (choice == 0 && test1 !=0)
    {
        is_executable = 1;
      }

    else if (choice == 1 && test1!=2){
  
      is_executable = 1;
    }
    else{
      printf("not executable");
    }
    if (is_executable){
      if (choice == 0)
      {
        mergeSort(array, 0, n-1, n);
        print_array(array, n);
      }
      else if (choice == 1)
      {
        mergeSort_reverse(array, 0, n-1, n);
        print_array(array, n);
      }
    }
    return 0;
}