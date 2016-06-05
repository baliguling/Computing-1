
     1	//By: Jonathan Wong, z3460680
     2	//09/03/2016
     3	// Tests whether a year is a leap year
     4	
     5	#include <stdio.h>
     6	#include <stdlib.h>
     7	#include <assert.h>
     8	#define START_OF_THE_GREGORIAN_CALENDAR 1582
     9	int main (int argc, char *argv[]){
    10	   int year;
    11	   printf("please enter the year you are interested in\n");
    12	   scanf("%d", &year);
    13	   assert (year >= START_OF_THE_GREGORIAN_CALENDAR);
    14	
    15	   if(year%400==0){
    16	    printf("%d is a leap year!\n", year);
    17	}
    18	   else if(year%4==0 && year%100 !=0){
    19	    printf("%d is a leap year!\n", year);
    20	}
    21	   else {
    22	    printf ("%d is not a leap year!\n", year);
    23	}
    24	return EXIT_SUCCESS;
    25	}
