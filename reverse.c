#include <stdlib.h>
#include <stdio.h>
#include <string.h>

char* reverse(char* str);

int main (int argc, char* argv[]) {
    //char* str1 = "I'm the best";
    char str2[] = "jl;kj;l adsjf lkadsj fl; j dsflkj a;dslfj; osdij ;ioa dvaj v";
    printf("%s\n", str2);
    reverse(str2);
    printf("%s\n", str2);

    return EXIT_SUCCESS;
}

char* reverse(char* str) {
    int strLen = strlen(str);
    int curPos = strLen - 1;
    int otherPos = 0;
    //char revString [strLen , + 1];
    char* revString = malloc(strLen + 1);
    if (strLen != 0) {
            while (curPos >= 0) {
                revString [otherPos] = str[curPos];
                otherPos += 1; curPos -= 1;
            }
    } revString[strLen] = '\0'; return revString;
}
