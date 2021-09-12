#include <stdio.h>
#include <stdlib.h>

/*
 * Read an image from the standard input and set the red value of each pixel to
 * zero.
 */
void remove_red()
{
	int i= 1; 
    char each_c[10];
	while (scanf("%s", each_c) != -1)
	{
		if (i>4 && (i - 2) % 3 == 0)
		{
			char red_pixel[] = "0";
			printf("%s ", red_pixel);
		}
		else
		{
			printf("%s ", each_c);
		}
		
		//print \n for formatting 
		if (i >= 4 && (i - 1) % 3 == 0)
		{
			printf("\n");
		}
		else{;}
		
		i++;
	}
	printf("\n");
}

/*
 * Read an image from the standard input and convert it from colour to black and white.
 */
void convert_to_black_and_white()
{
    int i= 1; 
	char each_c[10];
	while (scanf("%s", each_c) != -1)
	{
		if ( i > 4 )
		{
			int r_pix = strtol(each_c, NULL, 10);; 
			int g_pix, b_pix;
			for(int x=0; x<2; x++)
			{
				scanf("%s", each_c);
				if(x == 0)
				{
					g_pix = strtol(each_c, NULL, 10);
				}
				else if( x == 1 )
				{
					b_pix = strtol(each_c, NULL, 10);
				}
				else 
				{
					;
				}
			}
			
			int average = (r_pix + g_pix + b_pix)/3;
			printf("\n");
			for(int a=0; a<3; a++)
			{
				printf("%d ", average);
			}
			i = i + 2;
			
		}
		else
		{
			printf("%s ", each_c);
		}
		
		
		i++;
	}
	printf("\n");
}

/*
 * Read an image from the standard input and convert it to a square image.
 */
void instagram_square()
{
	int rows=0;
	int columns=0;
	char each_c[10];
	
	for (int i=0; i<3; i++)
	{
		scanf("%s", each_c);
		if (i == 2)
		{
			rows = strtol (each_c, NULL, 10);
		}
		else if (i == 1)
		{
			columns = strtol (each_c, NULL, 10);
		}
		else
		{
			printf("%s\n", each_c);
		}
		
	}
	
	
	if (rows == columns)
	{
		printf("%d %d\n",rows, columns);
		int i= 3; 
		while (scanf("%s", each_c) != -1)
		{
			printf("%s ", each_c);
			
			//****************print \n for formatting 
			if (i >= 3 && (i) % 3 == 0)
			{
				printf("\n");
			}
			else{;}
			
			i++;
		}
		printf("\n");
		
	}
		
	else if (rows > columns)
	{
		
		printf("%d %d\n", columns, columns);
		int max_entries = columns * columns * 3;
		int i= 3; 
		while (scanf("%s", each_c) != -1 && i <= max_entries)
		{
			printf("%s ", each_c);
			
			//****************print \n for formatting 
			if (i >= 3 && (i) % 3 == 0)
			{
				printf("\n");
			}
			else{;}
			
			i++;
		}
		
		printf("\n");
		
		
 		
	}
	//rows < columns
	else 
	{
		printf("%d %d\n", rows, rows);
		
		int row_enteries = columns * 3 ;//original pic
		int entries_after = rows * 3 ;//after
		
		int entry_count=-1;
		
		int i= 3; 
		while (scanf("%s", each_c) != -1)
		{
			entry_count++;
			if (entry_count <=  entries_after)
			{
				printf("%s ", each_c);
			}
			else{;}
			
			if (entry_count == row_enteries)
			{
				entry_count = 0;
			}
			else{;}
			
			//****************print \n for formatting 
			if (i >= 3 && (i) % 3 == 0)
			{
				printf("\n");
			}
			else{;}
			
			
			i++;
			
		}
		printf("\n");
		
		
	}
}

