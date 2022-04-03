/****************************************************************************
 * University of Zurich, Informatics II, Spring Semester 2022               *
 * Exercise 1 - Task 3: Sample Solution                                     *
 *                                                                          *
 * @date 2022-02-10                                                         *
 ****************************************************************************/

#include <stdio.h>
const int MAX_LENGTH = 1000;

void insertion_sort(int input[], int size) {
	for (int i = 1; i < size; i++) {
		int j = i - 1;
		int temp = input[i];
		while (j >= 0 && temp < input[j]) {
			input[j + 1] = input[j];
			j--;
		}
		input[j + 1] = temp;
	}
}

int main() {
	printf("Values of A separated by spaces (non-number to stop): ");
	int timestamps[MAX_LENGTH];
	int pos = 0;
	while (scanf("%d", &timestamps[pos]) == 1) {
		pos++;
	}

	insertion_sort(timestamps, pos);

	int longest_gap = 0;
	for (int i = 1; i < pos; i++) {
		int gap = timestamps[i] - timestamps[i - 1];
		if (gap > 1 && gap > longest_gap) {
			longest_gap = gap;
		}
	}

	printf("Longest gap: %d\n", longest_gap);
	printf("Oldest timestamp: %d\n", timestamps[0]);
	printf("Most recent timestamp: %d\n", timestamps[pos - 1]);

	return 0;
}