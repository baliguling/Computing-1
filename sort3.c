     1	//Jonathan Wong, z3460680
     2	//18/03/16
     3	//Sorts numbers in ascending order
     4	#include <stdio.h>
     5	#include <stdlib.h>
     6	
     7	int main (int argc, char * argv[]){
     8	   int first, second, third;
     9	   scanf ("%d %d %d", &first, &second, &third);
    10	
    11	   if(first<third && first<second){
    12	     printf("%d\n", first);
    13	   }else if(second<third && second<first){
    14	     printf("%d\n", second);
    15	   }else{
    16	     printf("%d\n", third);
    17	   }
    18	
    19	   if(first<third && first>second){
    20	     printf("%d\n", first);
    21	   }else if(first>third && first<second){
    22	     printf("%d\n", first);
    23	   }else if(second<third && second>first){
    24	     printf("%d\n", second);
    25	   }else if(second>third && second<first){
    26	     printf("%d\n", second);
    27	   }else{
    28	     printf("%d\n", third);
    29	   }
    30	
    31	   if(first>third && first>second){
    32	     printf("%d\n", first);
    33	   }else if(second>third && second>first){
    34	     printf("%d\n", second);
    35	   }else{
    36	     printf("%d\n", third);
    37	   }
    38	
    39	return EXIT_SUCCESS;
    40	}
