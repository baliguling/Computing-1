
     1	//Jonathan Wong, 3460680
     2	//09/03/2016
     3	//Tests Leap Year using C functions
     4	
     5	#include <stdio.h>
     6	#include <stdlib.h>
     7	#include <assert.h>
     8	#define START_OF_THE_GREGORIAN_CALENDAR 1582
     9	
    10	int isLeapYear (int year){
    11	    int LYear;
    12	    if(year%400==0){
    13	      LYear=1;
    14	    }
    15	    else if (year%4==0 && year%100 !=0){
    16	      LYear=1;
    17	    }
    18	    else{
    19	      LYear=0;
    20	    }
    21	    return LYear;
    22	}
    23	
    24	int main (int argc, char *argv[]){
    25	   int year;
    26	   int function;
    27	   printf("please enter the year you are interested in\n");
    28	   scanf("%d", &year);
    29	   assert (year >= START_OF_THE_GREGORIAN_CALENDAR);
    30	   function = isLeapYear(year);
    31	
    32	   if(function==1){
    33	     printf("%d is a leap year!\n", year);
    34	   }
    35	   else {
    36	     printf("%d is not a leap year!\n", year);
    37	   }
    38	
    39	return EXIT_SUCCESS;
    40	}
