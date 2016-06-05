// Jonathan Wong. z3460680
// 25/03/16
//Prints Danish Flag using loops
#include <stdio.h>
#include <stdlib.h>

#define Line "** *********\n"

void showDanish (void);

int main (int argc, char *argv[]) {

  showDanish();

  return EXIT_SUCCESS;
}

void showDanish() {
   int row = 0;

   while (row < 4){
      printf(Line);
      row += 1;
      if (row == 2) {
          printf("\n");
      }
   }
}
