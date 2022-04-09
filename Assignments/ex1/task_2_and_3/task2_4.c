/****************************************************************************
 * University of Zurich, Informatics II, Spring Semester 2022               *
 * Exercise 1 - Task 4                                     *
 *                                                                          *
 * @date 2022-02-10                                                         *
 ****************************************************************************/

#include <stdio.h>
const int MAX_LENGTH = 1000;
void insertion_sort(int a[], int length)
{
    for (int i = 1; i < length; i++) //from 2 to n (the first element can be ignored)
    {
        int key = a[i]; //i memorize the a[i] as key
        int j = i-1; //prendi in considerazione l'array da j a 2
        while (j >= 0 && a[j] > key)
        {
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = key;
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
    for (int i = 0; i < pos; i++)
    {
        int gap = timestamps[i] - timestamps[i-1];

        if (gap > longest_gap)
        {
            longest_gap = gap;
        }
    }
    

    printf("Longest gap: %d\n", longest_gap);


	return 0;
}