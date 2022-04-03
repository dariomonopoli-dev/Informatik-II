/****************************************************************************
 * University of Zurich, Informatics II, Spring Semester 2022               *
 * Exercise 4 - Task 7: Sample Solution                                     *
 *                                                                          *
 * @date 2022-03-09                                                         *
 ****************************************************************************/

#include <stdio.h>

#define MAX_LENGTH 1000
#define ASCENDING 1
#define DESCENDING -1

/**
 * Helper function for printing an array of integers
 */
void print(int input[], int size) {
	printf("[");
	for (int i = 0; i < size - 1; i++) {
		printf("%d, ", input[i]);
	}
	printf("%d]\n", input[size - 1]);
}

/**
 * Checks whether an array of integers is sorted in a given direction
 * @param input the array which shall be checked
 * @param size number of elements in the input array
 * @param direction the direction (ascending or descening) for which
                    the array shall be checked
 * @return 1 if the array is sorted in the given direction, 0 otherwise
 */
int is_sorted(int input[], int left, int right, const int direction) {
	for (int i = left + 1; i <= right; i++) {
		if ((input[i - 1] > input[i] && direction == ASCENDING) ||
			  (input[i - 1] < input[i] && direction == DESCENDING)) {
			return 0;
		}
	}
	return 1;
}

/**
 * Helper function to decide whether an integer should be put before another
 * integer according to a given sorting direction
 */
int is_put_before(int a, int b, const int direction) {
	if ((direction == ASCENDING && a < b) || (direction == DESCENDING && a > b)) {
		return 1;
	}
	else {
		return 0;
	}
}

/**
 * Sorts an array of integers in the given direction
 * @param input the array which shall be sorted
 * @param start first index from which the array shall be sorted
 * @param end last index until which the array shall be sorted
 * @param direction the direction (ascending or descending)
                    in which the array shall be sorted
 * @pre start >= 0 && end < size(input)
 * @post input is sorted in ascending or descending order
 */
void insertion_sort(int input[], int left, int right, int direction) {
	for (int i = left; i <= right; i++) {
		int j = i - 1;
		int temp = input[i];
		while (j >= left && is_put_before(temp, input[j], direction)) {
			input[j + 1] = input[j];
			j--;
		}
		input[j + 1] = temp;
	}
}

/**
 * Modified merging subroutine for the merge sort algorithm
 */
void merge(int input[], int left, int right, int middle, int direction, int temp[]) {
	// copy both halves of the input array to a temporary array
	for (int i = left; i <= middle; i++) {
		temp[i] = input[i];
	}
	for (int i = middle + 1; i <= right; i++) {
		temp[right + middle + 1 - i] = input[i];
	}
	int i = left;
	int j = right;
	// copy all elements back in correct order and merge the two halves
	for (int k = left; k <= right; k++) {
		if (is_put_before(temp[i], temp[j], direction)) {
			input[k] = temp[i];
			i++;
		}
		else {
			input[k] = temp[j];
			j--;
		}
	}
}

/**
 * Modified implementation of the merge sort algorithm
 */
void merge_sort_mod(int input[], int left, int right, int direction, int temp[]) {
	const int threshold = 6;
	if (is_sorted(input, left, right, direction)) {
		return;
	}
	else if (left < right) {
		if (right - left <= threshold) {
			insertion_sort(input, left, right, direction);
		}
		else {
			int middle = (left + right) / 2;
			merge_sort_mod(input, left, middle, direction, temp);
			merge_sort_mod(input, middle + 1, right, direction, temp);
			merge(input, left, right, middle, direction, temp);
		}
	}
}

int main() {
	int input[MAX_LENGTH];
	int temp[MAX_LENGTH];
	printf("Values of array separated by spaces (non-number to stop): ");
	int pos = 0;
	while (scanf("%d", &input[pos]) == 1) {
		pos++;
	}
	print(input, pos);
	merge_sort_mod(input, 0, pos - 1, ASCENDING, temp);
	print(input, pos);
  return 0;
}
