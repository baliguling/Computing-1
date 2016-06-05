#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define BYTES_PER_PIXEL 3
#define BITS_PER_PIXEL (BYTES_PER_PIXEL*8)
#define NUMBER_PLANES 1
#define PIX_PER_METRE 2835
#define MAGIC_NUMBER 0x4d42
#define NO_COMPRESSION 0
#define OFFSET 54
#define DIB_HEADER_SIZE 40
#define NUM_COLORS 0

#define SIZE 512
#define BMP_FILE "mandelbrot.bmp"
#define BLACK 0
#define WHITE 255

#define BOUNDED 4
#define MAX_ITERATIONS 256

typedef unsigned char  bits8;
typedef unsigned short bits16;
typedef unsigned int   bits32;

void writeHeader (FILE *file);
int escapeSteps (double x, double y);
int stepsToRed (int steps);
int stepsToGreen (int steps);
int stepsToBlue (int steps);

int main (int argc, char *argv[]) {

    assert (sizeof(bits8)  == 1);
    assert (sizeof(bits16) == 2);
    assert (sizeof(bits32) == 4);

    FILE *outputFile;
    outputFile = fopen(BMP_FILE, "wb");
    assert ((outputFile!=NULL) && "Cannot open file");
    writeHeader(outputFile);

    printf ("generating mandelbrot picture");

    int numBytes = (SIZE * SIZE * BYTES_PER_PIXEL);
    int pos = 0;
    bits8 byte;
    byte = BLACK;

    int xcoord = -256;
    int ycoord = -256;
    double zre;
    double zim;
    int escape;
    int red = 0;
    int green = 0;
    int blue = 0;

    while (pos < numBytes) {
        int printno;

        zre = xcoord/256.000000000000000 - 0.5;
        zim = ycoord/256.000000000000000;
        escape = escapeSteps(zre, zim);

        if(escape < BOUNDED) {
            red = BLACK;
            green = BLACK;
            blue = BLACK;
        } else {
            red = stepsToRed(escape);
            green = stepsToGreen(escape);
            blue = stepsToBlue(escape);
        }

        for (printno = 0; printno < BYTES_PER_PIXEL; printno++) {
            if (printno == 0) {
                byte = red;
            } else if (printno == 1){
                byte = green;
            } else if (printno == 2){
                byte = blue;
            }
            fwrite (&byte, sizeof byte, 1, outputFile);
            pos++;
        }

        xcoord = xcoord + 1;
        if (pos%SIZE == 0) {
             xcoord = -256;
            ycoord = ycoord + 1;
        }
    }

    fclose(outputFile);


    return EXIT_SUCCESS;
}

int stepsToRed (int steps){
    int color = steps;
    if (color == MAX_ITERATIONS) {
      color = color - 1;
    }
    color = BLACK + color;
    return color;
}

int stepsToGreen (int steps){
    int color = steps;
    if (color == MAX_ITERATIONS) {
      color = color - 1;
    }
    color = BLACK + color;
    return color;
}

int stepsToBlue (int steps){
    int color = steps;
    if (color == MAX_ITERATIONS) {
      color = color - 1;
    }
    color = BLACK + color;
    return color;
}

int escapeSteps (double x, double y){

    int iterations = 0;
    double originx = x;
    double originy = y;
    double re = 0;
    double im = 0;
    double tempre = 0;
    double tempim = 0;
    double distance = 0;

    while (distance < BOUNDED && iterations < MAX_ITERATIONS) {
        tempre = re;
        tempim = im;
        re = tempre*tempre - tempim*tempim + originx;
        im = 2*tempre*tempim + originy;
        distance = (re*re + im*im);
        iterations++;
    }

    return iterations;
}

void writeHeader (FILE *file) {
    assert(sizeof (bits8) == 1);
    assert(sizeof (bits16) == 2);
    assert(sizeof (bits32) == 4);

    bits16 magicNumber = MAGIC_NUMBER;
    fwrite (&magicNumber, sizeof magicNumber, 1, file);

    bits32 fileSize = OFFSET + (SIZE * SIZE * BYTES_PER_PIXEL);
    fwrite (&fileSize, sizeof fileSize, 1, file);

    bits32 reserved = 0;
    fwrite (&reserved, sizeof reserved, 1, file);

    bits32 offset = OFFSET;
    fwrite (&offset, sizeof offset, 1, file);

    bits32 dibHeaderSize = DIB_HEADER_SIZE;
    fwrite (&dibHeaderSize, sizeof dibHeaderSize, 1, file);

    bits32 width = SIZE;
    fwrite (&width, sizeof width, 1, file);

    bits32 height = SIZE;
    fwrite (&height, sizeof height, 1, file);

    bits16 planes = NUMBER_PLANES;
    fwrite (&planes, sizeof planes, 1, file);

    bits16 bitsPerPixel = BITS_PER_PIXEL;
    fwrite (&bitsPerPixel, sizeof bitsPerPixel, 1, file);

    bits32 compression = NO_COMPRESSION;
    fwrite (&compression, sizeof compression, 1, file);

    bits32 imageSize = (SIZE * SIZE * BYTES_PER_PIXEL);
    fwrite (&imageSize, sizeof imageSize, 1, file);

    bits32 hResolution = PIX_PER_METRE;
    fwrite (&hResolution, sizeof hResolution, 1, file);

    bits32 vResolution = PIX_PER_METRE;
    fwrite (&vResolution, sizeof vResolution, 1, file);

    bits32 numColors = NUM_COLORS;
    fwrite (&numColors, sizeof numColors, 1, file);

    bits32 importantColors = NUM_COLORS;
    fwrite (&importantColors, sizeof importantColors, 1, file);

}
