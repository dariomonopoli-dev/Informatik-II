#include <stdlib.h>
#include <stdio.h>

#define RED 1
#define BLUE 2
#define BLACK 3
#define VIOLET 4

void print(int* matrix, int size) {
	for (int row = 0; row < size; row++) {
		for (int col = 0; col < size; col++) {
			printf("%2d ", *(matrix + (row * size) + col));
		}
		printf("\n");
	}
}

void exchange(int* matrix, int row1, int col1, int row2, int col2, int size) {
	int temp = *(matrix + (row2 * size) + col2);
	*(matrix + (row2 * size) + col2) = *(matrix + (row1 * size) + col1);
	*(matrix + (row1 * size) + col1) = temp;
}

void segregate(int* matrix, int row_from, int row_to, int col_from, int col_to, int total_size) {
	const int current_size = row_to - row_from + 1;
	// BASE CASE
	// in a 2x2 matrix, the colours are sorted as required
	if (current_size == 2) {
		if (*(matrix + (row_from * total_size) + col_from + 1) == RED) {
			exchange(matrix, row_from, col_from, row_from, col_from + 1, total_size);
		}
		else if (*(matrix + (row_from + 1) * total_size + col_from) == RED) {
			exchange(matrix, row_from, col_from, row_from + 1, col_from, total_size);
		}
		else if (*(matrix + (row_from + 1) * total_size + col_from + 1) == RED) {
			exchange(matrix, row_from, col_from, row_from + 1, col_from + 1, total_size);
		}
		if (*(matrix + (row_from + 1) * total_size + col_from) == BLUE) {
			exchange(matrix, row_from, col_from + 1, row_from + 1, col_from, total_size);
		}
		else if (*(matrix + (row_from + 1) * total_size + col_from + 1) == BLUE) {
			exchange(matrix, row_from, col_from + 1, row_from + 1, col_from + 1, total_size);
		}
		if (*(matrix + (row_from + 1) * total_size + col_from + 1) == BLACK) {
			exchange(matrix, row_from + 1, col_from, row_from + 1, col_from + 1, total_size);
		}

		return;
	}

	// DIVIDE
	// subdivide the given matrix in the middle into four
	// submatrices of equal size
	int row_middle = row_from + (current_size / 2) - 1;
	int col_middle = col_from + (current_size / 2) - 1;

	// CONQUER
	// recursively apply the algorithm onto the four submatrices
	segregate(matrix, row_from, row_middle, col_from, col_middle, total_size);
	segregate(matrix, row_from, row_middle, col_middle + 1, col_to, total_size);
	segregate(matrix, row_middle + 1, row_to, col_from, col_middle, total_size);
	segregate(matrix, row_middle + 1, row_to, col_middle + 1, col_to, total_size);

	// COMBINE
	// switch for all rows the columns in the middle part
	for (int row = row_from; row <= row_to; row++) {
		for (int col = col_from + current_size / 4; col < col_from + current_size / 2; col++) {
			exchange(matrix, row, col, row, col + current_size / 4, total_size);
		}
	}
	// switch for all columns the rows in the middle part
	for (int col = col_from; col <= col_to; col++) {
		for (int row = row_from + current_size / 4; row < row_from + current_size / 2; row++) {
			exchange(matrix, row, col, row + current_size / 4, col, total_size);
		}
	}
}

int main() {
	const int size = 4;
	int matrix1[4][4] = {{1, 2, 3, 1}, {4, 3, 2, 4}, {1, 3, 3, 1}, {4, 2, 4, 2}};
	/*int matrix2[8][8] = {{4, 3, 1, 2, 4, 2, 1, 2},
	                     {1, 2, 3, 4, 3, 1, 4, 3},
	                     {1, 2, 2, 3, 3, 2, 3, 2},
	                     {4, 3, 4, 1, 1, 4, 4, 1},
	                     {4, 1, 3, 1, 1, 3, 2, 3},
	                     {3, 2, 4, 2, 2, 4, 1, 4},
	                     {1, 3, 4, 1, 3, 1, 1, 3},
	                     {4, 2, 2, 3, 2, 4, 2, 4}};*/
	int* matrix = malloc(size * size * sizeof(int));
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			*(matrix + (i * size) + j) = matrix1[i][j];
		}
	}
	print(matrix, size);
	segregate(matrix, 0, size - 1, 0, size - 1, size);
	printf("\n");
	print(matrix, size);
	return 0;
}
