// Jonathan Wong, z3460680
// 25/03/16
// Prints sequence of Wondrous numbers

#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

int printWondrous (int start);

int main (int argc, char* argv []) {

    return EXIT_SUCCESS;
}

int printWondrous(int start) {
   int loop = 6;

   while (start != 1) {
       if ((start & 1) == 0) {
          start = start/2;
       }
       else {
       (start = (start * 3) + 1);
       }
       printf("%d ", start);
       loop++;
   }
   return loop;
}
