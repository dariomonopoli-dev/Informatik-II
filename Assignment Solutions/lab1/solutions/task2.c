/****************************************************************************
 * University of Zurich, Informatics II, Spring Semester 2022               *
 * Exercise 1 - Task 2: Sample Solution                                    *
 *                                                                          *
 * @date 2022-02-10                                                         *
 ****************************************************************************/

#include <stdio.h>

// hard-coded maximum length for input strings
const int MAX_LENGTH = 1000;

/**
 * Checks whether a letter is a vowel letter (case-insensitive)
 * @param[letter] letter which shall be checked
 * @return 1 if letter is a vowel letter, 0 otherwise
 */
int is_vowel(char letter) {

	// check if letter is vowel letter
	if (letter == 'A' || letter == 'E' || letter == 'I' || letter =='O' || letter == 'U'
		|| letter == 'a' || letter == 'e' || letter == 'i' || letter =='o' || letter == 'u') {
		return 1;
	}
	else {
		return 0;
	}
}

/**
 * Finds the length of a string
 * @param[input_string] the string for which the length shall be determined
 * @return length of input_string
 * @pre input_string is null-terminated
 */
int get_length(char input_string[]) {
	int pos = 0;
	while (input_string[pos] != '\0') {
		pos++;
	}
	return pos;
}

/**
 * Counts the vowels in a string (case-insensitive)
 * @param[input_string] the string in which the vowels shall be counted
 * @return number of vowel letter in input_string
 * @pre input_string is null-terminated
 */
int count_vowels(char A[]) {
	int count_vowels = 0;
	int pos = 0;
	while (A[pos] != '\0') {
		if (is_vowel(A[pos])) {
			count_vowels++;
		}
		pos++;
	}
	return count_vowels;
}

void BS(char A[]) {
	int count_v = count_vowels(A);
	const int new_len = get_length(A) + 2 * count_v;
	char bsprache[new_len + 1];
	int pos_input = 0;
	int pos_bsprache = 0;
	while (A[pos_input] != '\0') {
		if (is_vowel(A[pos_input])) {
			bsprache[pos_bsprache] = A[pos_input];
			bsprache[pos_bsprache + 1] = 'b';
			bsprache[pos_bsprache + 2] = A[pos_input];
			pos_bsprache = pos_bsprache + 3;
		}
		else {
			bsprache[pos_bsprache] = A[pos_input];
			pos_bsprache = pos_bsprache + 1;
		}
		pos_input++;
	}
	bsprache[new_len] = '\0';
	printf("B-Sprache: %s\n", bsprache);

}

int main() {
	char A[MAX_LENGTH + 1];
	printf("Enter a string: ");
	scanf("%[^\n]s", A);

	printf("Number of vowels: %d\n", count_vowels(A));
	BS(A);
	return 0;
}
