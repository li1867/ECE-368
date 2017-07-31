
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#include "sorting.h"
int main(int argc, char * argv[]) {
	if(argc < 5)
	{
		printf("input error");
		return EXIT_FAILURE;
	}

	int size = 0;
	clock_t start_input, end_input, start_output, end_output, start_sort, end_sort;
	double sort_time;
	start_input = clock();
	long * array = Load_From_File(argv[2], &size);
	end_input = clock();

	double input_time = (double)(end_input - start_input) / CLOCKS_PER_SEC;
	int sequence = Print_Seq(argv[3], size);
	double N_Comp = 0;
	double N_Move = 0;

	if(strcmp(argv[1], "i") == 0)
	{
		start_sort = clock();
		Shell_Insertion_Sort(array, size, &N_Comp, &N_Move);
		end_sort = clock();
		sort_time = (double)(end_sort - start_sort) / CLOCKS_PER_SEC;
	}

	if(strcmp(argv[1], "s") == 0)
	{
		start_sort = clock();
		Shell_Selection_Sort(array, size, &N_Comp, &N_Move);
		end_sort = clock();
		sort_time = (double)(end_input - start_input) / CLOCKS_PER_SEC;
	}

	start_output = clock();
	int save = Save_To_File(argv[4], array, size);
	end_output = clock();
	double output_time = (double)(end_input - start_input) / CLOCKS_PER_SEC;
	double total_time = input_time + output_time;

	free(array);

	printf("Number of long integers read: %d\n",size);
	printf("Number of long integers stored: %d\n",save);
	printf("Length of sequence: %d\n",sequence);
	printf("Number of comparisions %le\n",N_Comp);
	printf("Number of moves: %le\n", N_Move);
	printf("I/O time: %le\n",total_time);
	printf("Sorting time: %le\n",sort_time);

	return EXIT_SUCCESS;
}
