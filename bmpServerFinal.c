/*
 *  bmpServer.c
 *  1917 serve that 3x3 bmp from lab3 Image activity
 *
 *  Created by Tim Lambert on 02/04/12.
 *  Containing code created by Richard Buckland on 28/01/11.
 *  Copyright 2012 Licensed under Creative Commons SA-BY-NC 3.0.
 *
 */

#include <stdlib.h>
#include <stdio.h>
#include <netinet/in.h>
#include <string.h>
#include <assert.h>
#include <unistd.h>
#include <math.h>

int waitForConnection (int serverSocket);
int makeServerSocket (int portno);
void serveBMP (int socket);
void serveHTML(int socket);

#define SIMPLE_SERVER_VERSION 1.0
#define REQUEST_BUFFER_SIZE 1000
#define DEFAULT_PORT 1888
#define NUMBER_OF_PAGES_TO_SERVE 10
// after serving this many pages the server will halt

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
#define BLACK 0
#define WHITE 255

#define FILE_SIZE 786486
#define BOUNDED 4
#define MAX_ITERATIONS 256

typedef unsigned char  bits8;
typedef unsigned short bits16;
typedef unsigned int   bits32;

void writeHeader (FILE *file);
int escapeSteps (double x, double y);
unsigned stepsToRed (int steps);
unsigned stepsToGreen (int steps);
unsigned stepsToBlue (int steps);

double xurl = 0.15;
double yurl = 0.15;
double zurl = 8;

int main (int argc, char *argv[]) {

   printf ("************************************\n");
   printf ("Starting simple server %f\n", SIMPLE_SERVER_VERSION);
   printf ("Serving bmps since 2012\n");

   int serverSocket = makeServerSocket (DEFAULT_PORT);
   printf ("Access this server at http://localhost:%d/\n", DEFAULT_PORT);
   printf ("************************************\n");

   char request[REQUEST_BUFFER_SIZE];

   int numberServed = 0;
   while (numberServed < NUMBER_OF_PAGES_TO_SERVE) {

      printf ("*** So far served %d pages ***\n", numberServed);

      int connectionSocket = waitForConnection (serverSocket);
      // wait for a request to be sent from a web browser, open a new
      // connection for this conversation

      // read the first line of the request sent by the browser
      int bytesRead;
      bytesRead = read (connectionSocket, request, (sizeof request)-1);
      assert (bytesRead >= 0);
      // were we able to read any data from the connection?

      // print entire request to the console
      printf (" *** Received http request ***\n %s\n", request);

      //send the browser a simple html page using http
      printf (" *** Sending http response ***\n");
      serveBMP(connectionSocket);
      short URLCoor = sscanf(request, "%*s /X%lf_Y%lf_Z%lfd.bmp", &xurl, &yurl, &zurl);
        if (URLCoor == 3){
            serveBMP(connectionSocket);
        }
        else{
            serveHTML(connectionSocket);}

      // close the connection after sending the page- keep aust beautiful
      close(connectionSocket);

      numberServed++;
   }

   // close the server connection after we are done- keep aust beautiful
   printf ("** shutting down the server **\n");
   close (serverSocket);

   return EXIT_SUCCESS;
}

void serveBMP (int socket) {
   char* message;

   // first send the http response header

   // (if you write stings one after another like this on separate
   // lines the c compiler kindly joins them togther for you into
   // one long string)
   message = "HTTP/1.0 200 OK\r\n"
                "Content-Type: image/bmp\r\n"
                "\r\n";
   printf ("about to send=> %s\n", message);
   write (socket, message, strlen (message));

   // now send the BMP
   unsigned char bmp[FILE_SIZE] = {
     0x42,0x4d,0x63,0x00,0x0c,0x00,0x00,0x00,
     0x00,0x00,0x36,0x00,0x00,0x00,0x28,0x00,
     0x00,0x00,0x00,0x02,0x00,0x00,0x00,0x02,
     0x00,0x00,0x00,0x00,0x18,0x00,0x00,0x00,
     0x00,0x00,0x00,0x00,0x0c,0x00,0xc3,0x0e,
     0x00,0x00,0xc3,0x0e,0x00,0x00,0x00,0x00,
     0x00,0x00,0x00,0x00,0x00,0x00};

    int numBytes = (SIZE * SIZE * BYTES_PER_PIXEL);
    int pos = 0;

    int xcoord = -256;
    int ycoord = -256;
    double zre;
    double zim;
    int escape;
    int bmpcount = 54;
    int zoom = 1;

    while (zurl != 0) {
      zoom = 2*zoom;
      zurl = zurl - 1;
    }
    zoom = zoom*256.000000000000000;

    while (pos < numBytes) {

        zre = xcoord/zoom + xurl;
        zim = ycoord/zoom + yurl;
        escape = escapeSteps(zre, zim);

        if(escape == BOUNDED) {
           bmp[bmpcount] = BLACK;
           bmp[bmpcount + 1] = BLACK;
           bmp[bmpcount + 2] = BLACK;
        } else {
           bmp[bmpcount] = stepsToRed(escape);
           bmp[bmpcount + 1] = stepsToGreen(escape);
           bmp[bmpcount + 2] = stepsToBlue(escape);
        }

        pos +=3;
        bmpcount +=3;

        xcoord = xcoord + 1;
        if (pos%SIZE == 0) {
             xcoord = -256;
            ycoord = ycoord + 1;
        }
    }
    write (socket, bmp, sizeof(bmp));
}

unsigned stepsToRed (int steps){
    int color = steps;
    if (color == MAX_ITERATIONS) {
      color = color - 1;
    }
    color = BLACK;
    return color;
}

unsigned stepsToGreen (int steps){
    int color = steps;
    if (color == MAX_ITERATIONS) {
      color = color - 1;
    }
    color = ((log(color))/log(16)) * 100;
    return color;
}

unsigned stepsToBlue (int steps){
    int color = steps;
    if (color == MAX_ITERATIONS) {
      color = color - 1;
    }
    color = (((log(color))/log(13)) * 100) + 20;
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

// start the server listening on the specified port number
int makeServerSocket (int portNumber) {

   // create socket
   int serverSocket = socket (AF_INET, SOCK_STREAM, 0);
   assert (serverSocket >= 0);
   // error opening socket

   // bind socket to listening port
   struct sockaddr_in serverAddress;
   memset ((char *) &serverAddress, 0,sizeof (serverAddress));

   serverAddress.sin_family      = AF_INET;
   serverAddress.sin_addr.s_addr = INADDR_ANY;
   serverAddress.sin_port        = htons (portNumber);

   // let the server start immediately after a previous shutdown
   int optionValue = 1;
   setsockopt (
      serverSocket,
      SOL_SOCKET,
      SO_REUSEADDR,
      &optionValue,
      sizeof(int)
   );

   int bindSuccess =
      bind (
         serverSocket,
         (struct sockaddr *) &serverAddress,
         sizeof (serverAddress)
      );

   assert (bindSuccess >= 0);
   // if this assert fails wait a short while to let the operating
   // system clear the port before trying again

   return serverSocket;
}

// wait for a browser to request a connection,
// returns the socket on which the conversation will take place
int waitForConnection (int serverSocket) {
   // listen for a connection
   const int serverMaxBacklog = 10;
   listen (serverSocket, serverMaxBacklog);

   // accept the connection
   struct sockaddr_in clientAddress;
   socklen_t clientLen = sizeof (clientAddress);
   int connectionSocket =
      accept (
         serverSocket,
         (struct sockaddr *) &clientAddress,
         &clientLen
      );

   assert (connectionSocket >= 0);
   // error on accept

   return (connectionSocket);
}

void serveHTML (int socket) {
       char* message;

       // first send the http response header
       message =
          "HTTP/1.0 200 Found\n"
          "Content-Type: text/html\n"
          "\n";
       printf ("about to send=> %s\n", message);
       write (socket, message, strlen (message));

       message =
          "<!DOCTYPE html>\n"
          "<script src=\"http://almondbread.cse.unsw.edu.au/tiles.js\"></script>"
          "\n";
       write (socket, message, strlen (message));

}
