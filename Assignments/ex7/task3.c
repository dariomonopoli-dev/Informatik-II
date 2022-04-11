
#include <stdio.h>
void get_span(int data[], int num_data, int* spans)
{
	//first span value is always 1
	spans[0] = 1;

	for (int i = 1; i < num_data; i++) {
		spans[i] = 1; // Initialize span value
		for (int j = i-1; (j>=0 && data[j] <= data[i]); j--)
        {
		    spans[i]++;
        }
	}
}


int main()
{
	int data[] = {6,3,4,5,2};
	int num_data= sizeof(data) / sizeof(data[0]);
	int spans[num_data];

	get_span(data, num_data, spans);
	for (int i = 0; i < num_data; i++) {
      printf("%d ", spans[i]);
   }

	return 0;
}
