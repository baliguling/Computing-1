    //Daniel Smith
    //3/5/13
    //Program prints out a custom sized chessboard

    /*
     *  chessboard.c
     *  create a 512x512 BMP of a chessboard, with user specified size
     *  bottom right square must be white.
     *
     *  Created by Richard Buckland on 14/04/11.
     *  Licensed under Creative Commons BY 3.0.
     *
     */

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
    #define BLACK 0
    #define WHITE 255
    #define ODD 1
    #define BLANK 0

    #define SIZE 512
    #define BMP_FILE "chess.bmp"

    typedef unsigned char  bits8;
    typedef unsigned short bits16;
    typedef unsigned int   bits32;

    void writeHeader (FILE *file);

    int main (int argc, char *argv[]) {

       // check that the types have the size i'm relying on here
       assert (sizeof(bits8)  == 1);
       assert (sizeof(bits16) == 2);
       assert (sizeof(bits32) == 4);


       FILE *outputFile;
       int squareSize;

       outputFile = fopen(BMP_FILE, "wb");
       assert ((outputFile!=NULL) && "Cannot open file");

       writeHeader(outputFile);

       printf ("Enter square size (must be a factor of %d): \n", SIZE);

       int get = scanf ("%d", &squareSize);
       get++;
       assert (SIZE % squareSize == 0);

       int numBytes = (SIZE * SIZE * BYTES_PER_PIXEL);
       int pos = 0;

       bits8 byte;
       byte = BLACK;

       int bytesPerSquare = BYTES_PER_PIXEL*squareSize;
       int fullRow = SIZE*squareSize*BYTES_PER_PIXEL;

       if(squareSize != SIZE){

           while (pos < numBytes) {
              while(pos%bytesPerSquare != 0){
                 fwrite (&byte, sizeof byte, 1, outputFile);
                 pos++;
              }


              if(pos%fullRow !=0){

                 if (byte == WHITE){
                    byte = BLACK;
                 } else if (byte == BLACK){
                    byte = WHITE;
                 }
              }

              if(pos<numBytes){
                 fwrite (&byte, sizeof byte, 1, outputFile);
                 pos++;
              }
           }
       } else {
          while (pos < numBytes) {
             byte = WHITE;
             fwrite (&byte, sizeof byte, 1, outputFile);
             pos++;
          }
       }


       fclose(outputFile);

       return EXIT_SUCCESS;
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


     /*  // send stuff to fix the header
       unsigned char bmp[] = {

        0x42, 0x00, 0x36, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x36, 0x00, 0x00, 0x00, 0x28, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x01, 0x00, 0x18, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x13, 0x00,
        0x00, 0x00, 0x13, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00,


        0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
        0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
        0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
        0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
        0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
        0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,};


       fwrite (bmp, sizeof(bmp), 1, file); */
    }
