#include <stdio.h>
#include <stdlib.h>

/*
 * Include the function prototypes of all those functions implemented in image_processing.c.
 * Do not remove or modify them in any way.
 */

void remove_red();
void convert_to_black_and_white();
void instagram_square();

int main(int argc, char *argv[]) {
        /* Task 1 needs to be completed here: Make sure that the command line arguments are correct. In case an error exists,
         * print the error message and terminate the program. Otherwise, invoke the corresponding
         * image processing function. */
		
		if (argc<2)
		{
			printf("Error: Expecting one command-line argument, which needs to be either 1, 2, or 3.\n");
			return 1;
		} 
		else{;} 
		
		int arg_num = strtol(argv[1], NULL, 10);
		
		if (argc > 2 || ( arg_num != 1 &&  arg_num != 2 &&  arg_num != 3) )
		{
			printf("Error: Expecting one command-line argument, which needs to be either 1, 2, or 3.\n");
			return 1;
		}
		else
		{
			
			if (arg_num == 1)
			{
				remove_red();
				
			}
			else if (arg_num == 2)
			{
				convert_to_black_and_white();
				
			}
			else
			{
				//printf("working\n");
				instagram_square();
			}

		}

        return 0;
}
