/****************************************************************************
 * University of Zurich, Informatics II, Spring Semester 2022               *
 * Exercise 2 - Task 3                                                      *
 *                                                                          *
 * @author <Dario Monopoli>                                                      *
 ****************************************************************************/

#include <stdio.h>

int count_blinks(int number)
{
	if (number == 1)
	{
		return 1;
	}
	else if (number == 2)
	{
		return 2;
	}
	else{
		return count_blinks(number-1) + count_blinks(number-2);
	}
	
}

int main() {
	int input;
	printf("Enter the number of blinks: ");
	scanf("%d", &input);

	int result = count_blinks(input);
	if (input ==1)
	{
		printf("The number of possible combinations with %d blink is %d",input, result);
	}
	else{
	printf("The number of possible combinations with %d blinks is %d",input, result);
	}

	return 0;
}
