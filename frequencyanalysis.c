#include <stdlib.h>
#include <stdio.h>
#define DIFFERENCE 32
int main(int argc, char * argv[]){
    char c;
    int stringLen = 0;
    int charCount[255] = {0};
    while ((c = getchar()) != EOF) {
            printf("%c",c);
            if (c >= 'A' && c <= 'Z') {
                    c = c + DIFFERENCE; stringLen++;
            } else if (c >= 'a' && c <= 'z') {
                stringLen++;
                } charCount[(int)c]++;
                } printf("the statistics of the file are\n");
            int pos = 'a';
            while (pos <= 'z') {
                    double frequency = (charCount[pos]*100.0)/stringLen;
                    printf ("character %c had count %d with frequency being %f\n", pos, charCount[pos], frequency);
                    pos++;
                    }
    return EXIT_SUCCESS;
}
