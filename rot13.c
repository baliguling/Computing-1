// Jonathan Wong, z3460680 and Shashika
// 23/03/16
// Decodes rot13

#include <stdlib.h>
#include <stdio.h>

char encode (char letter);

int main(int argc, char * argv[]){

   char character;

   printf("Enter a character:\n");
   scanf("%c", &character);
   printf("%c", encode(character));

   return EXIT_SUCCESS;
}

char encode (char letter){

   int character;
   character = letter;

   if (character <= 90 && character >= 65){
      character = character + 13;
      if (character > 90){
         character = character - 26;
      }
   } if (character <= 122 && character >= 97){
      character = character + 13;
      if (character > 122){
         character = character - 26;
      }
   } letter = character;
   return letter;
}
