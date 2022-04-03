#include <stdio.h>

void selection_sort(int A[], int n) {

	for (int i = 0; i < n - 1; i++) {
		int k = i;
		for(int j = i + 1; j < n; j++) {
			if(A[j] < A[k]) k = j;
		}
		// exchange A[i] and A[k];
		int temp = A[i];
		A[i] = A[k];
		A[k] = temp;
	}
	return;
}

void even_odd_selection_sort(int A[], int n){

	int even_array[n], odd_array[n];
	int odd_count = 0, even_count = 0;
	selection_sort(A, n);
	for (int i = 0; i < n; i++){
		if (A[i]%2 == 0){
			even_array[even_count] = A[i];
			even_count++;
		}
		else{
			odd_array[odd_count] = A[i];
			odd_count++;
		}
	}
    
	printf("Sorted even numbers: "); 
	for (int i = 0; i < even_count; i++){
		printf("%d ", even_array[i]);
	}

    printf("\nSorted odd numbers: ");
	for (int i = 0; i < odd_count; i++){
		printf("%d ", odd_array[i]);
	}
	return;
}

int main(int argc, const char * argv[]) {
	int A[100];
	int n = 0;

	printf("Values of A separated by spaces (non-number to stop):");
	
	while (scanf("%d", &A[n]) == 1) {
		n++;
	}

	scanf("%*s");
	
	printf("Result: ");
	even_odd_selection_sort(A, n);
}

// Linux, Mac: gcc task4.c -o task4; ./task4
