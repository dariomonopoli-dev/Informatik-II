/****************************************************************************
 * University of Zurich, Informatics II, Spring Semester 2022               *
 * Exercise 2 - Task 2: Sample Solution                                     *
 *                                                                          *
 * @date 2022-02-20                                                         *
 ****************************************************************************/

#include <stdio.h>
const int MAX_LENGTH = 1000;

/**
 * Returns the position of the second smallest element in an array
 * @param arr array in which the second smallest element shall be found
 * @param upper_limit array index until which the array is to be considered
 * @param smallest smallest element found so far
 * @param second_smallest second smallest element found so far
 * @pre elements of array are strictly positive and mutually distinct && 
        array has at least two elements && upper_limit >= 0
 */
int get_second(int arr[], int upper_limit, int smallest, int second_smallest) {
	/* Base case: if only the first element of the array is still to be considered, 
	there are three possible cases:
	   - 1a: the first element can be the smallest, then return the smallest until here
	   - 1b: the first element is the second smallest in the array, then return this element
	   - 1c: the first element is neither the smallest nor the second smallest, then return 
	         the second smallest until here
	 */
	if (upper_limit == 0) {
		if (arr[0] < smallest) {
			// case 1a
			return smallest;
		}
		else if (arr[0] < second_smallest && arr[0] != smallest) {
			// case 1b
			// note: the second part of the condition can apply for an array of length 2
			return arr[0];
		}
		else {
			// case 1c
			return second_smallest;
		}
	}

	/* Recursive case: if more than the first element of the array is to be considered, 
	check how the element at the upper bound influences minima determined until now and 
	then recursively apply the function to the remaining array
	*/
	if (smallest < 1) {
		/* handle the case where the recursive case has never been executed before and 
		therefore both variables smallest and second_smallest are below 1 */
		if (arr[upper_limit] < arr[upper_limit - 1]) {
			smallest = arr[upper_limit];
			second_smallest = arr[upper_limit - 1];
		}
		else {
			smallest = arr[upper_limit - 1];
			second_smallest = arr[upper_limit];			
		}
	}
	else {
		if (arr[upper_limit] < smallest) {
			second_smallest = smallest;
			smallest = arr[upper_limit];
		}
		else if (arr[upper_limit] < second_smallest && arr[upper_limit] != smallest) {
			/* note: the second part of the condition can apply if the second but last 
			element is the smallest in the array */
			second_smallest = arr[upper_limit];
		}
	}
	printf("get_second(arr, %d, %d, %d)\n", upper_limit, smallest, second_smallest);
	return get_second(arr, upper_limit - 1, smallest, second_smallest);
}

int main() {
	printf("Values of array separated by spaces (non-number to stop): ");
	int arr[MAX_LENGTH];
	int pos = 0;
	while (scanf("%d", &arr[pos]) == 1) {
		pos++;
	}

	int result = get_second(arr, pos - 1, -1, -1);
	printf("Second smallest element in array: %d\n", result);
	return 0;
}
