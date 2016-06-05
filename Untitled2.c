    /*
     *  mandelbrot.c
     *  Produces a web server which will serve images of small regions of
     *  the Mandelbrot set (given a location and the level of zoom to use).
     *
     *  Mandelbrot functions created by Daniel Krasjic and Jason Lim on 30/4/13.
     *  Server created by Tim Lambert on 02/04/12.
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
    #include "pixelColor.h"
    #include "mandelbrot.h"

    #define MAX_X_COORD 255.5
    #define MAX_Y_COORD 255.5
    //The co-ordinates of the centre of the furthest pixel.
    #define MAX_ITERATIONS 256
    #define ESCAPE_DISTANCE 4

    #define TRUE 1

    #define SIMPLE_SERVER_VERSION 1.0
    #define REQUEST_BUFFER_SIZE 1000
    #define DEFAULT_PORT 7191

    static long double findPixelGap(int zoomLevel);

    static int waitForConnection (int serverSocket);
    static int makeServerSocket (int portno);
    static void serveBMP (int socket, long double centreX, long double centreY, int zoom, int gotValues);


    int main (int argc, char *argv[]) {
       printf ("************************************\n");
       printf ("Starting simple server %f\n", SIMPLE_SERVER_VERSION);
       printf ("Serving bmps since 2012\n");

       int serverSocket = makeServerSocket (DEFAULT_PORT);
       printf ("Access this server at http://localhost:%d/\n", DEFAULT_PORT);
       printf ("************************************\n");

       char request[REQUEST_BUFFER_SIZE];

       int numberServed = 0;
       while (TRUE) {

          printf ("*** So far served %d pages ***\n", numberServed);

          int connectionSocket = waitForConnection (serverSocket);
          // wait for a request to be sent from a web browser, open a new
          // connection for this conversation

          // read the first line of the request sent by the browser
          int bytesRead;
          bytesRead = read (connectionSocket, request, (sizeof request)-1);
          assert (bytesRead >= 0);
          //were we able to read any data from the connection?

          long double centreX;
          long double centreY;
          int zoom;
          int gotValues = sscanf(request, "GET /X%Lf_Y%Lf_Z%d.bmp", &centreX, &centreY, &zoom);
          // reads in the data from the URL in terms of the zoom level and centre point

          // print entire request to the console
          printf (" *** Received http request ***\n %s\n", request);

          //send the browser a simple html page using http
          printf (" *** Sending http response ***\n");
          serveBMP(connectionSocket, centreX, centreY, zoom, gotValues);

          // close the connection after sending the page- keep aust beautiful
          close(connectionSocket);

          numberServed++;
       }

       // close the server connection after we are done- keep aust beautiful
       printf ("** shutting down the server **\n");
       close (serverSocket);

       return EXIT_SUCCESS;
    }

    static void serveBMP (int socket, long double centreX, long double centreY, int zoom, int gotValues){
       char* message;
       char* browser;

       //First send the http response header.

       //(if you write stings one after another like this on separate
       //lines the c compiler kindly joins them togther for you into
       //one long string).


       if(gotValues != 3){
          message = "HTTP/1.0 200 OK\r\n"
                      "Content-Type:text/html\r\n"
                      "\r\n";
          browser = "<!DOCTYPE html>\n"
                      "<html\n>"
                      "<script src=\"https://almondbread.openlearning.com/tileviewer.js\"></script>\n"
                      "</html\n>";
          write (socket, message, strlen (message));
          write (socket, browser, strlen (browser));

       }else{
          message = "HTTP/1.0 200 OK\r\n"
                    "Content-Type: image/bmp\r\n"
                    "\r\n";
          printf ("about to send=> %s\n", message);
          write (socket, message, strlen (message));

          //Now send the BMP
          unsigned char bmpheader[] = {
             0x42,0x4d,0x36,0x00,      //ID field, BMP file size
             0x0c,0x00,0x00,0x00,
             0x00,0x00,0x36,0x00,      //Location of start of pixel array
             0x00,0x00,

             0x28,0x00,0x00,0x00,      //Number of bytes in DIB header
             0x00,0x02,0x00,0x00,      //Width of BMP in pixels
             0x00,0x02,0x00,0x00,      //Height of BMP in pixels
             0x01,0x00,0x18,0x00,      //Number of color planes used, Number of bits per pixel.
             0x00,0x00,0x00,0x00,
             0x00,0x00,0x0c,0x00,      //Size of raw data in pixel array.
             0x13,0x0b,0x00,0x00,      //Horizontal resolution of image.
             0x13,0x0b,0x00,0x00,      //Vertical resolution of image.
             0x00,0x00,0x00,0x00,
             0x00,0x00,0x00,0x00,
          };
          write (socket, bmpheader, sizeof(bmpheader));

          unsigned char pixel[3];

          long double pixelY;           //The Y location of the centre of the current pixel.
          long double pixelX;           //The X location of the centre of the current pixel.
          long double pixelGap;         //The gap between the centre of each pixel.

          long double centrePixelX = centreX;       //The X location of the middle of the current tile.
          long double centrePixelY = centreY;       //The Y location of the middle of the current tile.
          int zoomLevel = zoom;                     //Current level of zoom.
          //These three are what the program reads from the url.

          int iterations;

          pixelGap = findPixelGap(zoomLevel);       //The gap between each pixel centre

          pixelX = -MAX_X_COORD*pixelGap + centrePixelX;        //Finds how far the pixel is from the centre
          pixelY = -MAX_Y_COORD*pixelGap + centrePixelY;        //then shifts it by how much the centre is away from (0,0).
          //Finds the first pixel of the tile; the very bottom left pixel is first.

          while(pixelY <= MAX_Y_COORD*pixelGap + centrePixelY){
             while((pixelX < (MAX_X_COORD)*pixelGap + centrePixelX) && (pixelY <= MAX_Y_COORD*pixelGap + centrePixelY)){
                //While both pixelX and pixelY are in the tile.

                iterations = escapeSteps(pixelX,pixelY);
                //Finds the iterations for the current pixel.

                pixel[0] = stepsToBlue(iterations);
                pixel[1] = stepsToGreen(iterations);
                pixel[2] = stepsToRed(iterations);
                write (socket, pixel, sizeof(pixel));

                pixelX = pixelX + pixelGap; //Moves to next pixel in the row.

             }

             pixelX = -MAX_X_COORD*pixelGap + centrePixelX;
             pixelY = pixelY + pixelGap;
             //Moves up one row.
             write (socket, pixel, sizeof(pixel));
          }
       }
    }

    // start the server listening on the specified port number
    static int makeServerSocket (int portNumber) {

       // create socket
       int serverSocket = socket (AF_INET, SOCK_STREAM, 0);
       assert (serverSocket >= 0);
       // error opening socket

       // bind socket to listening port
       struct sockaddr_in serverAddress;
       bzero ((char *) &serverAddress, sizeof (serverAddress));

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

    static int waitForConnection (int serverSocket) {
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


    static long double findPixelGap(int zoomLevel){
       long double findPixelGapReturn;
       int counter;
       counter = 0;
       findPixelGapReturn = 1;

       if(zoomLevel > 0){
          while(counter < zoomLevel){
             findPixelGapReturn = findPixelGapReturn*0.5;
             //Halves the distance between pixel centres for each level of zoom over 0.
             counter = counter + 1;
          }

       }else if(zoomLevel < 0){
          while(counter > zoomLevel){
             findPixelGapReturn = findPixelGapReturn*2;
             //Doubles the distance between pixel centres for each level of zoom under 0, i.e. negative zoom levels
          }
       }
       return findPixelGapReturn;
    }

    int escapeSteps(double x, double y){
       //Function to iterate a point to find if a point escapes the mandelbrot set
       //and if it does how many iterations it takes.
       int iterations = 1;
       long double previousX = 0;
       long double previousY = 0;
       long double originalX = x;
       long double originalY = y;

       while(((x*x)+(y*y) < ESCAPE_DISTANCE) && (iterations < MAX_ITERATIONS)){
          //While the distance to the pixel is less than 2 and not at maxiumum iterations.
          previousX = x;
          previousY = y;

          x = ((previousX*previousX) - (previousY*previousY)) + originalX;
          y = (2*previousX*previousY) + originalY;
          //z= z^2 + c


          iterations++;
       }
       return iterations;
    }
