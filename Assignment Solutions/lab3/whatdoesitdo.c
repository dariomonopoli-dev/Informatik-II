/****************************************************************************
 * University of Zurich, Informatics II, Spring Semester 2022               *
 * Exercise 3 - Task 1 (e): Sample Solution                                 *
 *                                                                          *
 * @date 2022-02-25                                                         *
 ****************************************************************************/

#include <stdio.h>

void maximal_sum_every_k(int A[], int n, int k) {
  int result = -1000;
  int i;
  int j;
  for (i = 0; i < n; i++) {
    int current = 0;
    for (j = i; j < n; j += k) {
      current = current + A[j];
    }
    if (current > result) {
      result = current;
    }
  }
  printf("Result: %d\n", result);
}

int main(int argc, const char* argv[]) {
  int A[100];
  int n = 0;
  int k = -1;
  printf("Values of A separated by spaces (non-number to stop):");

  while (scanf("%d", &A[n]) == 1) {
    n++;
  }

  scanf("%*s");
  printf("Enter k: ");
  scanf("%d", &k);
  maximal_sum_every_k(A, n, k);
}
