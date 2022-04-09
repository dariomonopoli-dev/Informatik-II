/****************************************************************************
 * University of Zurich, Informatics II, Spring Semester 2022               *
 * Exercise 1 - Task 3                                    *
 *                                                                          *
 * @date 2022-02-10   Dario Monopoli                                        *
 ****************************************************************************/

#include <stdio.h>

void selectionSort(int A[], int n) {
    for (int i = 0; i < n -1; i++){
        int k = i;
        for (int j = i+1; j<n; j++) {
            if (A[j] < A[k])
            {
                k=j;
            }

            int temp = A[i];
            A[i] = A[k];
            A[k] = temp;
            
        }
        
    }

}

void evenOddSelectionSort(int A[], int n){
    int odd_numbers[n], even_numbers[n];
    int odd_count, even_count;
    selectionSort(A, n);
    
    for (int i = 0; i<n; i++)
    {
        if (A[i]%2==0)
        {
            even_numbers[even_count] = A[i];
            even_count++;
        }

        else if (A[i]%2==1)
        {
            odd_numbers[odd_count] = A[i];
            odd_count++;

        }



    }
    
    printf("Sorted even array: \n");
    for (int i = 0; i<even_count; i++)
    {
        printf("%d \n", even_numbers[i]);
    }

    printf("Sorted Odd array: \n");
    for (int i = 0; i<odd_count; i++)
    {
        printf("%d ", odd_numbers[i]);
    }

}

int main(int argc, const char * argv[]) {
	int A[100];
	int n = 0;

	printf("Values of A separated by spaces (non-number to stop): ");
	
	while (scanf("%d", &A[n]) == 1) {
		n++;
	}

	scanf("%*s");
	
	
	evenOddSelectionSort(A, n);
}