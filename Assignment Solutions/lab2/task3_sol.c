/****************************************************************************
 * University of Zurich, Informatics II, Spring Semester 2022               *
 * Exercise 2 - Task 3: Sample Solution                                     *
 *                                                                          *
 * @date 2022-02-20                                                         *
 ****************************************************************************/

#include <stdio.h>

/**
 * Returns the number of ways how an LED can blink according to certain rules
 * @param num_blinks the total number of blinks by the LED
 * @pre num_blinks > 0
 */
int num_patterns(int num_blinks) {
	if (num_blinks == 1) {
		return 1;
	}
	if (num_blinks == 2) {
		return 2;
	}
	return num_patterns(num_blinks - 1) + num_patterns(num_blinks - 2);
}

int main() {
	int input;
	printf("Enter the number of blinks: ");
	scanf("%d", &input);
	int result = num_patterns(input);
	printf("Number of blink patterns: %d\n", result);
	return 0;
}
