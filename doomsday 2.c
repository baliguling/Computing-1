/*
 *  doomsday.c
 *  A program to test a function dayOfWeek which determines which
 *  day of the week a particular date falls on.
 *  (only for dates after the start of the Gregorian calendar).
 *
 *  Program stub created by Richard Buckland on 27/03/12
 *  This program by Tristan Muir
 *  Freely licensed under Creative Commons CC-BY-3.0
 *
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define THURSDAY 0
#define FRIDAY   1
#define SATURDAY 2
#define SUNDAY   3
#define MONDAY   4
#define TUESDAY  5
#define WEDNESDAY 6

#define TRUE 1
#define FALSE 0
#define DAYS_PER_WEEK 7

int dayOfWeek (int doomsday, int leapYear, int month, int day);

int main (int argc, char *argv[]) {

   assert (dayOfWeek (THURSDAY,  FALSE,  4,  4) == THURSDAY);
   assert (dayOfWeek (FRIDAY,    FALSE,  6,  6) == FRIDAY);
   assert (dayOfWeek (MONDAY,    FALSE,  8,  8) == MONDAY);
   assert (dayOfWeek (WEDNESDAY, FALSE, 10, 10) == WEDNESDAY);
   assert (dayOfWeek (FRIDAY,    FALSE, 12, 12) == FRIDAY);
   assert (dayOfWeek (THURSDAY,  FALSE,  9,  5) == THURSDAY);
   assert (dayOfWeek (FRIDAY,    FALSE,  5,  9) == FRIDAY);
   assert (dayOfWeek (SUNDAY,    FALSE,  7, 11) == SUNDAY);
   assert (dayOfWeek (TUESDAY,   FALSE, 11,  7) == TUESDAY);
   assert (dayOfWeek (WEDNESDAY, FALSE,  3,  7) == WEDNESDAY);

   assert (dayOfWeek (THURSDAY,  FALSE,  4,  5) == FRIDAY);
   assert (dayOfWeek (SATURDAY,  FALSE,  6,  5) == FRIDAY);
   assert (dayOfWeek (MONDAY,    FALSE,  8,  9) == TUESDAY);
   assert (dayOfWeek (WEDNESDAY, FALSE, 10,  9) == TUESDAY);
   assert (dayOfWeek (FRIDAY,    FALSE, 12, 20) == SATURDAY);
   assert (dayOfWeek (THURSDAY,  FALSE,  9,  9) == MONDAY);
   assert (dayOfWeek (FRIDAY,    FALSE,  5,  5) == MONDAY);
   assert (dayOfWeek (SUNDAY,    FALSE,  7,  7) == WEDNESDAY);
   assert (dayOfWeek (TUESDAY,   FALSE, 11, 11) == SATURDAY);
   assert (dayOfWeek (THURSDAY,  FALSE,  3, 30) == SATURDAY);

   assert (dayOfWeek (TUESDAY,   FALSE,  2, 28) == TUESDAY);
   assert (dayOfWeek (TUESDAY,   FALSE,  2, 27) == MONDAY);
   assert (dayOfWeek (THURSDAY,  FALSE,  1,  3) == THURSDAY);

   //Tests bt Tristan Muir
   //I wanted to be helpful and submit some good ones and I would
   //have done more but the group seems to have submitted a pretty
   //comprehensive list.
   assert (dayOfWeek (FRIDAY,    TRUE,   2, 29) == FRIDAY);
   assert (dayOfWeek (THURSDAY,  TRUE,   3, 30) == SATURDAY);
   assert (dayOfWeek (THURSDAY,  TRUE,   1,  3) == WEDNESDAY);

   //santas birthday this year
   assert (dayOfWeek (THURSDAY,  FALSE,  12,  25) == WEDNESDAY);

   // birthday of Winnie
   assert (dayOfWeek (MONDAY, FALSE, 11, 29) == TUESDAY);

   // Random holidays from 2012 - 2013
   assert (dayOfWeek (THURSDAY, FALSE, 2, 10) == SUNDAY);
   assert (dayOfWeek (THURSDAY, FALSE, 1, 26) == SATURDAY);
   assert (dayOfWeek (THURSDAY, FALSE, 3, 29) == FRIDAY);
   assert (dayOfWeek (THURSDAY, FALSE, 4, 25) == THURSDAY);
   assert (dayOfWeek (THURSDAY, FALSE, 11, 28) == THURSDAY);
   assert (dayOfWeek (THURSDAY, FALSE, 12, 25) == WEDNESDAY);
   assert (dayOfWeek (THURSDAY, FALSE, 11, 11) == MONDAY);
   assert (dayOfWeek (WEDNESDAY, TRUE, 1, 23) == MONDAY);
   assert (dayOfWeek (WEDNESDAY, TRUE, 1, 1) == SUNDAY);
   assert (dayOfWeek (WEDNESDAY, TRUE, 4, 6) == FRIDAY);
   assert (dayOfWeek (WEDNESDAY, TRUE, 4, 7) == SATURDAY);
   assert (dayOfWeek (WEDNESDAY, TRUE, 7, 20) == FRIDAY);
   assert (dayOfWeek (WEDNESDAY, TRUE, 11, 6) == TUESDAY);


   // why not add my birthday by Jason Godfrey
   assert (dayOfWeek (FRIDAY, FALSE, 10, 10) == FRIDAY);

   //My Birthday - Contribution by James Ritchie

   assert (dayOfWeek (THURSDAY, TRUE, 2, 28) == WEDNESDAY);
   assert (dayOfWeek (THURSDAY, FALSE, 2, 28) == THURSDAY);

   assert (dayOfWeek (THURSDAY, FALSE,   5, 27) == MONDAY);
   assert (dayOfWeek (SATURDAY,  TRUE,   1, 17) == FRIDAY);
   assert (dayOfWeek (MONDAY,    TRUE,   2, 11) == THURSDAY);
   assert (dayOfWeek (SUNDAY,    FALSE,  2, 11) == THURSDAY);
   assert (dayOfWeek (THURSDAY,  FALSE,  2, 24) == SUNDAY);
   assert (dayOfWeek (MONDAY, TRUE, 1, 4) == MONDAY);

   assert (dayOfWeek (THURSDAY,  FALSE,  4,  4) == THURSDAY);
   assert (dayOfWeek (FRIDAY,    FALSE,  6,  6) == FRIDAY);
   assert (dayOfWeek (MONDAY,    FALSE,  8,  8) == MONDAY);
   assert (dayOfWeek (WEDNESDAY, FALSE, 10, 10) == WEDNESDAY);
   assert (dayOfWeek (FRIDAY,    FALSE, 12, 12) == FRIDAY);
   assert (dayOfWeek (THURSDAY,  FALSE,  9,  5) == THURSDAY);
   assert (dayOfWeek (FRIDAY,    FALSE,  5,  9) == FRIDAY);
   assert (dayOfWeek (SUNDAY,    FALSE,  7, 11) == SUNDAY);
   assert (dayOfWeek (TUESDAY,   FALSE, 11,  7) == TUESDAY);
   assert (dayOfWeek (WEDNESDAY, FALSE,  3,  7) == WEDNESDAY);
   assert (dayOfWeek (WEDNESDAY, FALSE,  8, 12) == SUNDAY);
   assert (dayOfWeek (THURSDAY,  FALSE,  4,  5) == FRIDAY);
   assert (dayOfWeek (SATURDAY,  FALSE,  6,  5) == FRIDAY);
   assert (dayOfWeek (MONDAY,    FALSE,  8,  9) == TUESDAY);
   assert (dayOfWeek (WEDNESDAY, FALSE, 10,  9) == TUESDAY);
   assert (dayOfWeek (FRIDAY,    FALSE, 12, 20) == SATURDAY);
   assert (dayOfWeek (THURSDAY,  FALSE,  9,  9) == MONDAY);
   assert (dayOfWeek (FRIDAY,    FALSE,  5,  5) == MONDAY);
   assert (dayOfWeek (SUNDAY,    FALSE,  7,  7) == WEDNESDAY);
   assert (dayOfWeek (TUESDAY,   FALSE, 11, 11) == SATURDAY);
   assert (dayOfWeek (THURSDAY,  FALSE,  3, 30) == SATURDAY);
   assert (dayOfWeek (TUESDAY,  FALSE,  7,  10) == MONDAY);

   assert (dayOfWeek (TUESDAY,   FALSE,  2, 28) == TUESDAY);
   assert (dayOfWeek (TUESDAY,   FALSE,  2, 27) == MONDAY);
   assert (dayOfWeek (THURSDAY,  FALSE,  1,  3) == THURSDAY);

   // Additional tests
   assert (dayOfWeek (WEDNESDAY, TRUE,   1, 31) == TUESDAY);
   assert (dayOfWeek (MONDAY,    FALSE,  1, 31) == MONDAY);




   assert (dayOfWeek (TUESDAY,   TRUE,   1,  4) == TUESDAY);

   assert (dayOfWeek (WEDNESDAY, FALSE,  1,  6) == SATURDAY);
   assert (dayOfWeek (WEDNESDAY, FALSE, 12, 25) == TUESDAY);
   assert (dayOfWeek (WEDNESDAY, TRUE,   2, 29) == WEDNESDAY);
   assert (dayOfWeek (THURSDAY,  TRUE,   2, 11) == SUNDAY);

   assert (dayOfWeek (MONDAY,    TRUE,   2, 29) == MONDAY);
   assert (dayOfWeek (MONDAY,    TRUE,   2, 28) == SUNDAY);
   assert (dayOfWeek (MONDAY,    TRUE,   2, 27) == SATURDAY);
   assert (dayOfWeek (MONDAY,    TRUE,   1,  3) == SUNDAY);

   assert (dayOfWeek (WEDNESDAY, TRUE,  1,  23) == MONDAY);
   assert (dayOfWeek (THURSDAY,  TRUE,  3,  19) == TUESDAY);

   //Testing boundaries for different kind of year
   //year: 2000 - doomsday: TUESDAY - leap year
   assert (dayOfWeek (TUESDAY, TRUE,  1,  1) == SATURDAY);
   assert (dayOfWeek (TUESDAY, TRUE, 12, 31) == SUNDAY);
   assert (dayOfWeek (TUESDAY, TRUE,  2, 29) == TUESDAY);
   assert (dayOfWeek (TUESDAY, TRUE,  3,  1) == WEDNESDAY);

   assert (dayOfWeek (THURSDAY, FALSE, 3, 20) == WEDNESDAY);
   assert (dayOfWeek (THURSDAY, FALSE, 3, 21) == THURSDAY);
   assert (dayOfWeek (THURSDAY, FALSE, 3, 22) == FRIDAY);
   assert (dayOfWeek (THURSDAY, FALSE, 3, 23) == SATURDAY);

   //year: 1984 - doomsday: WEDNESDAY - leap year
   assert (dayOfWeek (WEDNESDAY, TRUE,  1,  1) == SUNDAY);
   assert (dayOfWeek (WEDNESDAY, TRUE, 12, 31) == MONDAY);
   assert (dayOfWeek (WEDNESDAY, TRUE,  2, 29) == WEDNESDAY);
   assert (dayOfWeek (WEDNESDAY, TRUE,  3,  1) == THURSDAY);

   //year: 1900 - doomsday: WEDNESDAY - non leap year
   assert (dayOfWeek (WEDNESDAY, FALSE,  1,  1) == MONDAY);
   assert (dayOfWeek (WEDNESDAY, FALSE, 12, 31) == MONDAY);
   assert (dayOfWeek (WEDNESDAY, FALSE,  2, 28) == WEDNESDAY);
   assert (dayOfWeek (WEDNESDAY, FALSE,  3,  1) == THURSDAY);

   //year: 2011 - doomsday: MONDAY - non leap year
   assert (dayOfWeek (MONDAY, FALSE,  1,  1) == SATURDAY);
   assert (dayOfWeek (MONDAY, FALSE, 12, 31) == SATURDAY);
   assert (dayOfWeek (MONDAY, FALSE,  2, 28) == MONDAY);
   assert (dayOfWeek (MONDAY, FALSE,  3,  1) == TUESDAY);
   assert (dayOfWeek (MONDAY, FALSE,  5, 23) == MONDAY);

   //testing each month for a leap year (2012)
   assert (dayOfWeek (WEDNESDAY, TRUE,  1,  1) == SUNDAY);
   assert (dayOfWeek (WEDNESDAY, TRUE,  2,  1) == WEDNESDAY);
   assert (dayOfWeek (WEDNESDAY, TRUE,  3,  1) == THURSDAY);
   assert (dayOfWeek (WEDNESDAY, TRUE,  4,  1) == SUNDAY);
   assert (dayOfWeek (WEDNESDAY, TRUE,  5,  1) == TUESDAY);
   assert (dayOfWeek (WEDNESDAY, TRUE,  6,  1) == FRIDAY);
   assert (dayOfWeek (WEDNESDAY, TRUE,  7,  1) == SUNDAY);
   assert (dayOfWeek (WEDNESDAY, TRUE,  8,  1) == WEDNESDAY);
   assert (dayOfWeek (WEDNESDAY, TRUE,  9,  1) == SATURDAY);
   assert (dayOfWeek (WEDNESDAY, TRUE, 10,  1) == MONDAY);
   assert (dayOfWeek (WEDNESDAY, TRUE, 11,  1) == THURSDAY);
   assert (dayOfWeek (WEDNESDAY, TRUE, 12,  1) == SATURDAY);

   //testing each month for a non leap year (2009)
   assert (dayOfWeek (SATURDAY, FALSE,  1,  1) == THURSDAY);
   assert (dayOfWeek (SATURDAY, FALSE,  2,  1) == SUNDAY);
   assert (dayOfWeek (SATURDAY, FALSE,  3,  1) == SUNDAY);
   assert (dayOfWeek (SATURDAY, FALSE,  4,  1) == WEDNESDAY);
   assert (dayOfWeek (SATURDAY, FALSE,  5,  1) == FRIDAY);
   assert (dayOfWeek (SATURDAY, FALSE,  6,  1) == MONDAY);
   assert (dayOfWeek (SATURDAY, FALSE,  7,  1) == WEDNESDAY);
   assert (dayOfWeek (SATURDAY, FALSE,  8,  1) == SATURDAY);
   assert (dayOfWeek (SATURDAY, FALSE,  9,  1) == TUESDAY);
   assert (dayOfWeek (SATURDAY, FALSE, 10,  1) == THURSDAY);
   assert (dayOfWeek (SATURDAY, FALSE, 11,  1) == SUNDAY);
   assert (dayOfWeek (SATURDAY, FALSE, 12,  1) == TUESDAY);

   //random various tests
   assert (dayOfWeek (MONDAY,   TRUE,  3, 24) == THURSDAY);
   assert (dayOfWeek (MONDAY,   FALSE, 3, 24) == THURSDAY);
   assert (dayOfWeek (THURSDAY, FALSE, 2, 17) == SUNDAY);
   assert (dayOfWeek (THURSDAY, TRUE,  2, 17) == SATURDAY);
   assert (dayOfWeek (SUNDAY,   TRUE, 11, 14) == SUNDAY);
   assert (dayOfWeek (SUNDAY,   TRUE,  2, 21) == SATURDAY);
   assert (dayOfWeek (MONDAY,   TRUE,  5,  7) == SATURDAY);
   assert (dayOfWeek (MONDAY,   FALSE, 7,  5) == TUESDAY);
   assert (dayOfWeek (SATURDAY, FALSE, 2, 28) == SATURDAY);
   assert (dayOfWeek (MONDAY,   TRUE,  2, 28) == SUNDAY);
   assert (dayOfWeek (MONDAY,   TRUE,  2, 29) == MONDAY);
   assert (dayOfWeek (MONDAY,   TRUE,  1,  3) == SUNDAY);
   assert (dayOfWeek (MONDAY,   TRUE,  1,  4) == MONDAY);
   assert (dayOfWeek (SATURDAY, FALSE, 1,  3) == SATURDAY);
   assert (dayOfWeek (SATURDAY, FALSE, 1,  4) == SUNDAY);
   assert (dayOfWeek (TUESDAY,  FALSE, 6, 6) == TUESDAY);
   assert (dayOfWeek (TUESDAY,  TRUE, 1, 31) == MONDAY);
   //different fix for the commented issue
   assert (dayOfWeek (WEDNESDAY, TRUE,  1,  6) == FRIDAY);

   // tests 2012
   assert (dayOfWeek(WEDNESDAY, TRUE, 11, 16) == FRIDAY); // today
   assert (dayOfWeek(WEDNESDAY, TRUE, 11, 17) == SATURDAY); // tomorrow
   assert (dayOfWeek(WEDNESDAY, TRUE, 10, 13) == SATURDAY);
   assert (dayOfWeek(WEDNESDAY, TRUE, 6, 28) == THURSDAY);
   assert (dayOfWeek(WEDNESDAY, TRUE, 1, 8) == SUNDAY);
   assert (dayOfWeek(WEDNESDAY, TRUE, 1, 23) == MONDAY);
   assert (dayOfWeek(WEDNESDAY, TRUE, 2, 9) == THURSDAY);
   assert (dayOfWeek(WEDNESDAY, TRUE, 2, 14) == TUESDAY);
   assert (dayOfWeek(WEDNESDAY, TRUE, 2, 26) == SUNDAY);
   assert (dayOfWeek(WEDNESDAY, TRUE, 2, 28) == TUESDAY);
   assert (dayOfWeek(WEDNESDAY, TRUE, 3, 1) == THURSDAY);
   assert (dayOfWeek(WEDNESDAY, TRUE, 3, 5) == MONDAY);
   assert (dayOfWeek(WEDNESDAY, TRUE, 4, 6) == FRIDAY);
   assert (dayOfWeek(WEDNESDAY, TRUE, 4, 30) == MONDAY);
   assert (dayOfWeek(WEDNESDAY, TRUE, 5, 9) == WEDNESDAY);
   assert (dayOfWeek(WEDNESDAY, TRUE, 5, 18) == FRIDAY);
   assert (dayOfWeek(WEDNESDAY, TRUE, 5, 28) == MONDAY);
   assert (dayOfWeek(WEDNESDAY, TRUE, 6, 3) == SUNDAY);
   assert (dayOfWeek(WEDNESDAY, TRUE, 6, 20) == WEDNESDAY);
   assert (dayOfWeek(WEDNESDAY, TRUE, 6, 30) == SATURDAY);
   assert (dayOfWeek(WEDNESDAY, TRUE, 7, 3) == TUESDAY);
   assert (dayOfWeek(WEDNESDAY, TRUE, 7, 12) == THURSDAY);
   assert (dayOfWeek(WEDNESDAY, TRUE, 7, 27) == FRIDAY);
   assert (dayOfWeek(WEDNESDAY, TRUE, 8, 1) == WEDNESDAY);
   assert (dayOfWeek(WEDNESDAY, TRUE, 8, 13) == MONDAY);
   assert (dayOfWeek(WEDNESDAY, TRUE, 9, 11) == TUESDAY);
   assert (dayOfWeek(WEDNESDAY, TRUE, 9, 24) == MONDAY);
   assert (dayOfWeek(WEDNESDAY, TRUE, 10, 11) == THURSDAY);
   assert (dayOfWeek(WEDNESDAY, TRUE, 10, 26) == FRIDAY);
   assert (dayOfWeek(WEDNESDAY, TRUE, 11, 19) == MONDAY);
   assert (dayOfWeek(WEDNESDAY, TRUE, 11, 24) == SATURDAY);
   assert (dayOfWeek(WEDNESDAY, TRUE, 12, 24) == MONDAY);
   assert (dayOfWeek(WEDNESDAY, TRUE, 12, 30) == SUNDAY);

   // 2011
   assert (dayOfWeek(MONDAY, FALSE, 1, 12) == WEDNESDAY);
   assert (dayOfWeek(MONDAY, FALSE, 2, 22) == TUESDAY);
   assert (dayOfWeek(MONDAY, FALSE, 3, 4) == FRIDAY);
   assert (dayOfWeek(MONDAY, FALSE, 4, 23) == SATURDAY);
   assert (dayOfWeek(MONDAY, FALSE, 5, 8) == SUNDAY);
   assert (dayOfWeek(MONDAY, FALSE, 6, 17) == FRIDAY);
   assert (dayOfWeek(MONDAY, FALSE, 7, 12) == TUESDAY);
   assert (dayOfWeek(MONDAY, FALSE, 8, 7) == SUNDAY);
   assert (dayOfWeek(MONDAY, FALSE, 9, 27) == TUESDAY);
   assert (dayOfWeek(MONDAY, FALSE, 10, 5) == WEDNESDAY);
   assert (dayOfWeek(MONDAY, FALSE, 11, 30) == WEDNESDAY);
   assert (dayOfWeek(MONDAY, FALSE, 12, 19) == MONDAY);
   assert (dayOfWeek(MONDAY, FALSE, 11, 6) == SUNDAY); // added by James Line

    // 2013
   assert (dayOfWeek(THURSDAY, FALSE, 4, 20) == SATURDAY);
   assert (dayOfWeek(THURSDAY, FALSE, 2, 13) == WEDNESDAY);
   assert (dayOfWeek(THURSDAY, FALSE, 5, 19) == SUNDAY);

   // contribution to the unit tests
   assert (dayOfWeek(SATURDAY, FALSE, 10, 9) == FRIDAY);
   assert (dayOfWeek(THURSDAY, FALSE, 10, 19) == SATURDAY);
   assert (dayOfWeek(MONDAY, TRUE, 1, 1) == FRIDAY);
   assert (dayOfWeek(WEDNESDAY, TRUE, 11, 15) == THURSDAY);
   assert (dayOfWeek(WEDNESDAY, TRUE, 2, 7) == TUESDAY); // added by James Line

   // additional unit tests for each month of the year
   // one each for a leap year and a non-leap year (various years)
   // a few days chosen less than or equal to the doomsday
   // added by dave dobbs

   assert (dayOfWeek (TUESDAY,  FALSE,  1,  13)  == FRIDAY);
   assert (dayOfWeek (MONDAY,  TRUE,  1,  29)  == FRIDAY);
   assert (dayOfWeek (THURSDAY,  FALSE,  2,  11)  == MONDAY);
   assert (dayOfWeek (MONDAY,  TRUE,  2,  7)  == SUNDAY);
   assert (dayOfWeek (SATURDAY,  FALSE,  3,  19)  == THURSDAY);
   assert (dayOfWeek (WEDNESDAY,  TRUE,  3,  30)  == FRIDAY);
   assert (dayOfWeek (SUNDAY,  FALSE,  3,  1)  == MONDAY);
   assert (dayOfWeek (SUNDAY,  TRUE,  3,  30)  == TUESDAY);
   assert (dayOfWeek (MONDAY,  FALSE,  4,  24)  == SUNDAY);
   assert (dayOfWeek (WEDNESDAY,  TRUE,  4,  28)  == SATURDAY);
   assert (dayOfWeek (TUESDAY,  FALSE,  4,  1)  == SATURDAY);
   assert (dayOfWeek (THURSDAY,  TRUE,  4,  1)  == MONDAY);
   assert (dayOfWeek (MONDAY,  FALSE,  5,  31)  == TUESDAY);
   assert (dayOfWeek (MONDAY,  FALSE,  5,  2)  == MONDAY);
   assert (dayOfWeek (FRIDAY,  TRUE,  5,  26)  == MONDAY);
   assert (dayOfWeek (TUESDAY,  FALSE,  5,  1)  == MONDAY);
   assert (dayOfWeek (THURSDAY,  TRUE,  5,  2)  == THURSDAY);
   assert (dayOfWeek (SATURDAY,  FALSE,  6,  30)  == TUESDAY);
   assert (dayOfWeek (FRIDAY,  TRUE,  6,  22)  == SUNDAY);
   assert (dayOfWeek (THURSDAY,  FALSE,  7,  6)  == SATURDAY);
   assert (dayOfWeek (FRIDAY,  TRUE,  7,  28)  == MONDAY);
   assert (dayOfWeek (WEDNESDAY,  FALSE,  8,  31)  == FRIDAY);
   assert (dayOfWeek (SUNDAY,  TRUE,  8,  28)  == SATURDAY);
   assert (dayOfWeek (SUNDAY,  FALSE,  9,  25)  == SATURDAY);
   assert (dayOfWeek (WEDNESDAY,  TRUE,  9,  2)  == SUNDAY);
   assert (dayOfWeek (THURSDAY,  FALSE,  10,  30)  == WEDNESDAY);
   assert (dayOfWeek (MONDAY,  TRUE,  10,  28)  == FRIDAY);
   assert (dayOfWeek (SATURDAY,  FALSE,  11,  1)  == SUNDAY);
   assert (dayOfWeek (MONDAY,  TRUE,  11,  27)  == SUNDAY);
   assert (dayOfWeek (TUESDAY,  FALSE,  12,  1)  == FRIDAY);
   assert (dayOfWeek (THURSDAY,  TRUE,  12,  31)  == TUESDAY);
   assert (dayOfWeek (THURSDAY,  TRUE,  12,  2)  == MONDAY);
   assert (dayOfWeek (THURSDAY,   TRUE,  1, 15) == MONDAY);
   assert (dayOfWeek (THURSDAY,   TRUE,  2, 29) == THURSDAY);
   assert (dayOfWeek (SATURDAY,  FALSE,  1, 27) == TUESDAY);
   assert (dayOfWeek (SATURDAY,   TRUE,  1, 27) == MONDAY);
   assert (dayOfWeek (SUNDAY,     TRUE, 12, 21) == TUESDAY);
   assert (dayOfWeek (THURSDAY,   TRUE,  8,  1) == THURSDAY);
   assert (dayOfWeek (WEDNESDAY,  TRUE,  8, 11) == SATURDAY);
   assert (dayOfWeek (WEDNESDAY,  TRUE,  3, 17) == SATURDAY);
   assert (dayOfWeek (MONDAY,     TRUE,  3,  1) == TUESDAY);

   // Contribution by AB. Random months and dates for all years starting from 2012 (at top) to 1900.
   // Calculated using Excel with correction for Excel's wrong leap year determination for 1900, the reason
   // for which this is interesting in itself)
   // Fixed instances where it was asking for 29th day of Feburary in a non leap year and last day of
   // Feburary is the doomsday (date modified: 22.3.13, by AFJ)

   assert (dayOfWeek (WEDNESDAY, TRUE, 12, 19) ==  WEDNESDAY);
   assert (dayOfWeek (MONDAY,	  FALSE, 3, 9) ==  WEDNESDAY);
   assert (dayOfWeek (SUNDAY,    FALSE, 8, 26) ==  THURSDAY);
   assert (dayOfWeek (SATURDAY,  FALSE, 12, 12) ==  SATURDAY);
   assert (dayOfWeek (FRIDAY,    TRUE, 9, 12) ==  FRIDAY);
   assert (dayOfWeek (WEDNESDAY, FALSE, 12, 29) ==  SATURDAY);
   assert (dayOfWeek (TUESDAY,   FALSE, 6, 8) ==  THURSDAY);
   assert (dayOfWeek (MONDAY,    FALSE, 9, 31) ==  SATURDAY);
   assert (dayOfWeek (SUNDAY,    TRUE, 10, 26) ==  TUESDAY);
   assert (dayOfWeek (FRIDAY,    FALSE, 7, 19) ==  SATURDAY);
   assert (dayOfWeek (THURSDAY,  FALSE, 10, 1) ==  TUESDAY);
   assert (dayOfWeek (WEDNESDAY, FALSE, 8, 15) ==  WEDNESDAY);
   assert (dayOfWeek (TUESDAY,   TRUE, 7, 21) ==  FRIDAY);
   assert (dayOfWeek (SUNDAY,    FALSE, 7, 18) ==  SUNDAY);
   assert (dayOfWeek (SATURDAY,  FALSE, 4, 6) ==  MONDAY);
   assert (dayOfWeek (FRIDAY,    FALSE, 6, 10) ==  TUESDAY);
   assert (dayOfWeek (THURSDAY,  TRUE, 10, 10) ==  THURSDAY);
   assert (dayOfWeek (TUESDAY,   FALSE, 1, 24) ==  TUESDAY);
   assert (dayOfWeek (MONDAY,    FALSE, 3, 17) ==  THURSDAY);
   assert (dayOfWeek (SUNDAY,    FALSE, 11, 19) ==  FRIDAY);
   assert (dayOfWeek (SATURDAY,  TRUE, 12, 12) ==  SATURDAY);
   assert (dayOfWeek (THURSDAY,  FALSE, 9, 17) ==  TUESDAY);
   assert (dayOfWeek (WEDNESDAY, FALSE, 7, 20) ==  FRIDAY);
   assert (dayOfWeek (TUESDAY,   FALSE, 12, 29) ==  FRIDAY);
   assert (dayOfWeek (MONDAY,    TRUE, 1, 8) ==  FRIDAY);
   assert (dayOfWeek (SATURDAY,  FALSE, 3, 19) ==  THURSDAY);
   assert (dayOfWeek (FRIDAY,    FALSE, 5, 3) ==  SATURDAY);
   assert (dayOfWeek (THURSDAY,  FALSE, 8, 15) ==  THURSDAY);
   assert (dayOfWeek (WEDNESDAY, TRUE, 8, 17) ==  FRIDAY);
   assert (dayOfWeek (MONDAY,    FALSE, 10, 5) ==  WEDNESDAY);
   assert (dayOfWeek (SUNDAY,    FALSE, 2, 25) ==  THURSDAY);
   assert (dayOfWeek (SATURDAY,  FALSE, 4, 8) ==  WEDNESDAY);
   assert (dayOfWeek (FRIDAY,    TRUE, 6, 2) ==  MONDAY);
   assert (dayOfWeek (WEDNESDAY, FALSE, 10, 28) ==  SUNDAY);
   assert (dayOfWeek (TUESDAY,   FALSE, 7, 9) ==  SUNDAY);
   assert (dayOfWeek (MONDAY,    FALSE, 9, 25) ==  SUNDAY);
   assert (dayOfWeek (SUNDAY,    TRUE, 7, 3) ==  SATURDAY);
   assert (dayOfWeek (FRIDAY,    FALSE, 10, 29) ==  WEDNESDAY);
   assert (dayOfWeek (THURSDAY,  FALSE, 2, 6) ==  WEDNESDAY);
   assert (dayOfWeek (WEDNESDAY, FALSE, 2, 1) ==  THURSDAY);
   assert (dayOfWeek (TUESDAY,   TRUE, 6, 16) ==  FRIDAY);
   assert (dayOfWeek (SUNDAY,    FALSE, 2, 20) ==  SATURDAY);
   assert (dayOfWeek (SATURDAY,  FALSE, 8, 17) ==  MONDAY);
   assert (dayOfWeek (FRIDAY,    FALSE, 5, 4) ==  SUNDAY);
   assert (dayOfWeek (THURSDAY,  TRUE, 12, 30) ==  MONDAY);
   assert (dayOfWeek (TUESDAY,   FALSE, 7, 1) ==  SATURDAY);
   assert (dayOfWeek (MONDAY,    FALSE, 5, 25) ==  WEDNESDAY);
   assert (dayOfWeek (SUNDAY,    FALSE, 7, 14) ==  WEDNESDAY);
   assert (dayOfWeek (SATURDAY,  TRUE, 12, 7) ==  MONDAY);
   assert (dayOfWeek (THURSDAY,  FALSE, 2, 9) ==  SATURDAY);
   assert (dayOfWeek (WEDNESDAY, TRUE, 2, 29) ==  WEDNESDAY);
   assert (dayOfWeek (TUESDAY,   FALSE, 10, 1) ==  SUNDAY);
   assert (dayOfWeek (MONDAY,    TRUE, 4, 24) ==  SUNDAY);
   assert (dayOfWeek (SATURDAY,  FALSE, 10, 20) ==  TUESDAY);
   assert (dayOfWeek (FRIDAY,    FALSE, 10, 29) ==  WEDNESDAY);
   assert (dayOfWeek (THURSDAY,  FALSE, 5, 20) ==  MONDAY);
   assert (dayOfWeek (WEDNESDAY, TRUE, 9, 1) ==  SATURDAY);
   assert (dayOfWeek (MONDAY,    FALSE, 5, 9) ==  MONDAY);
   assert (dayOfWeek (SUNDAY,    FALSE, 5, 14) ==  FRIDAY);
   assert (dayOfWeek (SATURDAY,  FALSE, 4, 29) ==  WEDNESDAY);
   assert (dayOfWeek (FRIDAY,    TRUE, 4, 26) ==  SATURDAY);
   assert (dayOfWeek (WEDNESDAY, FALSE, 8, 9) ==  THURSDAY);
   assert (dayOfWeek (TUESDAY,   FALSE, 11, 18) ==  SATURDAY);
   assert (dayOfWeek (MONDAY,    FALSE, 1, 8) ==  SATURDAY);
   assert (dayOfWeek (SUNDAY,    TRUE, 1, 31) ==  SATURDAY);
   assert (dayOfWeek (FRIDAY,    FALSE, 5, 7) ==  WEDNESDAY);
   assert (dayOfWeek (THURSDAY,  FALSE, 6, 3) ==  MONDAY);
   assert (dayOfWeek (WEDNESDAY, FALSE, 5, 24) ==  THURSDAY);
   assert (dayOfWeek (TUESDAY,   TRUE, 12, 27) ==  WEDNESDAY);
   assert (dayOfWeek (SUNDAY,    FALSE, 1, 12) ==  TUESDAY);
   assert (dayOfWeek (SATURDAY,  FALSE, 10, 27) ==  TUESDAY);
   assert (dayOfWeek (FRIDAY,    FALSE, 11, 25) ==  TUESDAY);
   assert (dayOfWeek (THURSDAY,  TRUE, 2, 17) ==  SATURDAY);
   assert (dayOfWeek (TUESDAY,   FALSE, 5, 4) ==  THURSDAY);
   assert (dayOfWeek (MONDAY,    FALSE, 7, 1) ==  FRIDAY);
   assert (dayOfWeek (SUNDAY,    FALSE, 11, 19) ==  FRIDAY);
   assert (dayOfWeek (SATURDAY,  TRUE, 11, 1) ==  SUNDAY);
   assert (dayOfWeek (THURSDAY,  FALSE, 1, 28) ==  MONDAY);
   assert (dayOfWeek (WEDNESDAY, FALSE, 8, 17) ==  FRIDAY);
   assert (dayOfWeek (TUESDAY,   FALSE, 11, 1) ==  WEDNESDAY);
   assert (dayOfWeek (MONDAY,    TRUE, 11, 28) ==  MONDAY);
   assert (dayOfWeek (SATURDAY,  FALSE, 7, 3) ==  FRIDAY);
   assert (dayOfWeek (FRIDAY,    FALSE, 2, 18) ==  TUESDAY);
   assert (dayOfWeek (THURSDAY,  FALSE, 4, 12) ==  FRIDAY);
   assert (dayOfWeek (WEDNESDAY, TRUE, 6, 23) ==  SATURDAY);
   assert (dayOfWeek (MONDAY,    FALSE, 5, 31) ==  TUESDAY);
   assert (dayOfWeek (SUNDAY,    FALSE, 5, 22) ==  SATURDAY);
   assert (dayOfWeek (SATURDAY,  FALSE, 8, 7) ==  FRIDAY);
   assert (dayOfWeek (FRIDAY,    TRUE, 11, 9) ==  SUNDAY);
   assert (dayOfWeek (WEDNESDAY, FALSE, 8, 7) ==  TUESDAY);
   assert (dayOfWeek (TUESDAY,   FALSE, 12, 2) ==  SATURDAY);
   assert (dayOfWeek (MONDAY,    FALSE, 5, 14) ==  SATURDAY);
   assert (dayOfWeek (SUNDAY,    TRUE, 8, 14) ==  SATURDAY);
   assert (dayOfWeek (FRIDAY,    FALSE, 6, 2) ==  MONDAY);
   assert (dayOfWeek (THURSDAY,  FALSE, 10, 10) ==  THURSDAY);
   assert (dayOfWeek (WEDNESDAY, FALSE, 5, 29) ==  TUESDAY);
   assert (dayOfWeek (TUESDAY,   TRUE, 7, 15) ==  SATURDAY);
   assert (dayOfWeek (SUNDAY,    FALSE, 5, 29) ==  SATURDAY);
   assert (dayOfWeek (SATURDAY,  FALSE, 5, 28) ==  THURSDAY);
   assert (dayOfWeek (FRIDAY,    FALSE, 1, 7) ==  TUESDAY);
   assert (dayOfWeek (THURSDAY,  TRUE, 10, 4) ==  FRIDAY);
   assert (dayOfWeek (TUESDAY,   FALSE, 6, 26) ==  MONDAY);
   assert (dayOfWeek (MONDAY,    FALSE, 5, 2) ==  MONDAY);
   assert (dayOfWeek (SUNDAY,    FALSE, 1, 31) ==  SUNDAY);
   assert (dayOfWeek (SATURDAY,  TRUE, 8, 17) ==  MONDAY);
   assert (dayOfWeek (THURSDAY,  FALSE, 12, 19) ==  THURSDAY);
   assert (dayOfWeek (WEDNESDAY, FALSE, 8, 16) ==  THURSDAY);
   assert (dayOfWeek (TUESDAY,   FALSE, 6, 7) ==  WEDNESDAY);
   assert (dayOfWeek (MONDAY,    TRUE, 1, 9) ==  SATURDAY);
   assert (dayOfWeek (SATURDAY,  FALSE, 11, 18) ==  WEDNESDAY);
   assert (dayOfWeek (FRIDAY,    FALSE, 1, 7) ==  TUESDAY);
   assert (dayOfWeek (THURSDAY,  FALSE, 11, 22) ==  FRIDAY);
   assert (dayOfWeek (WEDNESDAY, FALSE, 11, 11) ==  SUNDAY);

   // Just to test peoples handling of neg numbers :D
   assert (dayOfWeek (THURSDAY,  FALSE, 10, 31) ==  THURSDAY);
   assert (dayOfWeek (THURSDAY,  FALSE, 11,  0) ==  THURSDAY);

   // year 1988 - doomsday is MONDAY
   assert (dayOfWeek (MONDAY,    TRUE,   1,  4) == MONDAY);
   assert (dayOfWeek (MONDAY,    TRUE,   2, 29) == MONDAY);
   assert (dayOfWeek (MONDAY,    TRUE,   4, 16) == SATURDAY);
   assert (dayOfWeek (MONDAY,    TRUE,   3,  7) == MONDAY);

   // FALSE DATES (with true assertions)
   assert (dayOfWeek (MONDAY,	 FALSE,  2, 29) == TUESDAY);
   assert (dayOfWeek (WEDNESDAY, FALSE,  9, 31) == MONDAY);
   assert (dayOfWeek (WEDNESDAY, TRUE,  12, 32) == TUESDAY);

   // First and last day of each month in 2012.
   assert (dayOfWeek (WEDNESDAY, TRUE,   1,  1)  ==  SUNDAY);
   assert (dayOfWeek (WEDNESDAY, TRUE,   1,  31) ==  TUESDAY);
   assert (dayOfWeek (WEDNESDAY, TRUE,   2,  1)  ==  WEDNESDAY);
   assert (dayOfWeek (WEDNESDAY, TRUE,   2,  29) ==  WEDNESDAY);
   assert (dayOfWeek (WEDNESDAY, TRUE,   3,  1)  ==  THURSDAY);
   assert (dayOfWeek (WEDNESDAY, TRUE,   3,  31) ==  SATURDAY);
   assert (dayOfWeek (WEDNESDAY, TRUE,   4,  1)  ==  SUNDAY);
   assert (dayOfWeek (WEDNESDAY, TRUE,   4,  30) ==  MONDAY);
   assert (dayOfWeek (WEDNESDAY, TRUE,   5,  1)  ==  TUESDAY);
   assert (dayOfWeek (WEDNESDAY, TRUE,   5,  31) ==  THURSDAY);
   assert (dayOfWeek (WEDNESDAY, TRUE,   6,  1)  ==  FRIDAY);
   assert (dayOfWeek (WEDNESDAY, TRUE,   6,  30) ==  SATURDAY);
   assert (dayOfWeek (WEDNESDAY, TRUE,   7,  1)  ==  SUNDAY);
   assert (dayOfWeek (WEDNESDAY, TRUE,   7,  31) ==  TUESDAY);
   assert (dayOfWeek (WEDNESDAY, TRUE,   8,  1)  ==  WEDNESDAY);
   assert (dayOfWeek (WEDNESDAY, TRUE,   8,  31) ==  FRIDAY);
   assert (dayOfWeek (WEDNESDAY, TRUE,   9,  1)  ==  SATURDAY);
   assert (dayOfWeek (WEDNESDAY, TRUE,   9,  30) ==  SUNDAY);
   assert (dayOfWeek (WEDNESDAY, TRUE,   10, 1)  ==  MONDAY);
   assert (dayOfWeek (WEDNESDAY, TRUE,   10, 31) ==  WEDNESDAY);
   assert (dayOfWeek (WEDNESDAY, TRUE,   11, 1)  ==  THURSDAY);
   assert (dayOfWeek (WEDNESDAY, TRUE,   11, 30) ==  FRIDAY);
   assert (dayOfWeek (WEDNESDAY, TRUE,   12, 1)  ==  SATURDAY);
   assert (dayOfWeek (WEDNESDAY, TRUE,   12, 31) ==  MONDAY);

   assert (dayOfWeek (FRIDAY,    TRUE,  1,  11) == FRIDAY);

   // Testing Christmas day of this year (2012) which is a leap
   // year and next year (2013) which is not a leap year
   assert (dayOfWeek (WEDNESDAY, TRUE,  12, 25) == TUESDAY);
   assert (dayOfWeek (THURSDAY,  FALSE, 12, 25) == WEDNESDAY);

   assert (dayOfWeek (MONDAY,  FALSE, 4, 3) == SUNDAY);
   assert (dayOfWeek (MONDAY,  FALSE, 4, 5) == TUESDAY);

   // LB: two 'random' dates added.
   assert (dayOfWeek (WEDNESDAY, TRUE,  5,  10) == THURSDAY);
   assert (dayOfWeek (WEDNESDAY, TRUE,  9,  29) == SATURDAY);

   assert (dayOfWeek (WEDNESDAY, TRUE, 11, 12) == MONDAY);

   // My birthday this year, because I was creative enough to think of it
   assert (dayOfWeek (WEDNESDAY, FALSE,  3,  24) == SATURDAY);


   // Copying the birthday, because mine's only here once.
   assert (dayOfWeek (FRIDAY, FALSE, 3, 9) == SUNDAY);
   assert (dayOfWeek (WEDNESDAY, TRUE, 3, 9) == FRIDAY);
   // So let's add it twice this time
   assert (dayOfWeek (WEDNESDAY, TRUE, 10, 9) == TUESDAY);

   //testing date for start of the next milenium
   assert (dayOfWeek (FRIDAY, FALSE, 1, 1) == WEDNESDAY);

   assert (dayOfWeek (THURSDAY, FALSE, 7, 27) == SATURDAY);
   assert (dayOfWeek (MONDAY, TRUE, 6, 15) == WEDNESDAY);

   assert (dayOfWeek (WEDNESDAY, FALSE,  2, 26)  == MONDAY);

   assert (dayOfWeek (TUESDAY,   TRUE,  2,  28) == MONDAY);
   assert (dayOfWeek (TUESDAY,   TRUE,  2,  27) == SUNDAY);
   assert (dayOfWeek (THURSDAY,  TRUE,  1,  3)  == WEDNESDAY);
   assert (dayOfWeek (MONDAY,   FALSE,  2,  13) == SUNDAY);
   assert (dayOfWeek (TUESDAY,   TRUE,  2,  10) == THURSDAY);
   assert (dayOfWeek (THURSDAY,  FALSE,  1,  11)  == FRIDAY);
   assert (dayOfWeek (THURSDAY,  TRUE,  1,  16)  == TUESDAY);
   assert (dayOfWeek (THURSDAY, FALSE, 3, 20) == WEDNESDAY);
   assert (dayOfWeek (THURSDAY, FALSE, 3, 21) == THURSDAY);
   assert (dayOfWeek (THURSDAY, FALSE, 8, 20) == TUESDAY);

   assert (dayOfWeek (THURSDAY, FALSE, 3, 9) == SATURDAY);

   // Actual 2012 doomsday
   assert (dayOfWeek (WEDNESDAY, TRUE, 12, 21) == FRIDAY);

   assert (dayOfWeek (THURSDAY, TRUE, 5, 1) == WEDNESDAY);

   //The release of my favourite movie and "space camp" were all on doomsdays.
   //Here's the birth date of the current danish prime minister (Oliver Nordon)
   assert (dayOfWeek(MONDAY, FALSE, 12, 14) == WEDNESDAY);

   //my birthday in 1994 (not leap year) - Joshua Achermann
   assert (dayOfWeek (MONDAY, FALSE, 9, 25) == SUNDAY);

   //my birthday, a random date, and the date of Doc Brown's first time travel experiment
   //Daniel Smith
   assert(dayOfWeek(THURSDAY, FALSE, 8, 23) == FRIDAY);
   assert(dayOfWeek(SATURDAY, FALSE, 3, 23) == MONDAY);
   assert(dayOfWeek(THURSDAY, FALSE, 10, 26) == SATURDAY);

   //my birthday in 1994 and the beginning of the millenium (the year 2000) - Robert Tran
   assert(dayOfWeek(MONDAY, FALSE, 12, 17) == SATURDAY);
   assert(dayOfWeek(TUESDAY, TRUE, 1, 1) == SATURDAY);

   //A random date - John Wiseheart
   assert (dayOfWeek (FRIDAY, FALSE, 7, 13) == SUNDAY);

   //since birthdays seem to be all the rage - Daniel Li
   assert (dayOfWeek (THURSDAY, FALSE, 2, 14) == THURSDAY);

   // The due date! - Owen Cassidy
   assert (dayOfWeek (THURSDAY, FALSE, 4, 5) == FRIDAY);

   //All my birthdays - Mark Brodie
   assert (dayOfWeek(SUNDAY, FALSE, 3, 14) == SUNDAY);
   assert (dayOfWeek(MONDAY, FALSE, 3, 14) == MONDAY);
   assert (dayOfWeek(TUESDAY, FALSE, 3, 14) == TUESDAY);
   assert (dayOfWeek(THURSDAY, TRUE, 3, 14) == THURSDAY);
   assert (dayOfWeek(FRIDAY, FALSE, 3, 14) == FRIDAY);
   assert (dayOfWeek(SATURDAY, FALSE, 3, 14) == SATURDAY);
   assert (dayOfWeek(SUNDAY, FALSE, 3, 14) == SUNDAY);
   assert (dayOfWeek(TUESDAY, TRUE, 3, 14) == TUESDAY);
   assert (dayOfWeek(WEDNESDAY, FALSE, 3, 14) == WEDNESDAY);
   assert (dayOfWeek(THURSDAY, FALSE, 3, 14) == THURSDAY);
   assert (dayOfWeek(FRIDAY, FALSE, 3, 14) == FRIDAY);
   assert (dayOfWeek(SUNDAY, TRUE, 3, 14) == SUNDAY);
   assert (dayOfWeek(MONDAY, FALSE, 3, 14) == MONDAY);
   assert (dayOfWeek(TUESDAY, FALSE, 3, 14) == TUESDAY);
   assert (dayOfWeek(WEDNESDAY, FALSE, 3, 14) == WEDNESDAY);
   assert (dayOfWeek(FRIDAY, TRUE, 3, 14) == FRIDAY);
   assert (dayOfWeek(SATURDAY, FALSE, 3, 14) == SATURDAY);
   assert (dayOfWeek(SUNDAY, FALSE, 3, 14) == SUNDAY);
   assert (dayOfWeek(MONDAY, FALSE, 3, 14) == MONDAY);
   assert (dayOfWeek(WEDNESDAY, TRUE, 3, 14) == WEDNESDAY);
   assert (dayOfWeek(THURSDAY, FALSE, 3, 14) == THURSDAY);

   // my birthday this year - Andy Wong
   assert (dayOfWeek (THURSDAY, FALSE, 4, 20) == SATURDAY);

   // The birth and fall of Dennis Ritchie - Victor Lim
   assert (dayOfWeek(FRIDAY, FALSE, 9, 9) == TUESDAY);
   assert (dayOfWeek(MONDAY, FALSE, 10, 12) == WEDNESDAY);

   // obligatory birthday addition - andrew nguyen
   assert (dayOfWeek (MONDAY, FALSE, 12, 8) == THURSDAY);

   // Birthday + leap test: IH
   assert (dayOfWeek (SATURDAY,  TRUE,  2,  14)  == FRIDAY);
   assert (dayOfWeek (MONDAY,  FALSE,  10,  13)  == THURSDAY);

   // Of course I'll add my birthday (in the year I was born)
   // + the date my current favourite song was released :3 - Jarrod Calisura
   assert (dayOfWeek (MONDAY, FALSE, 8, 24) == WEDNESDAY);
   assert (dayOfWeek (WEDNESDAY, TRUE, 1, 29) == SUNDAY);

   // the day a great was born
   assert (dayOfWeek (MONDAY, FALSE, 12, 10) == SATURDAY);

   //Let's up the nerdy ante by considering these dates in
   //1977 and 1968, respectively, by Kai Zen.
   assert (dayOfWeek (MONDAY,    FALSE,  5,  25) == WEDNESDAY);
   assert (dayOfWeek (THURSDAY,  TRUE,   4,  2) == TUESDAY);

   //My Birthday and other days, by Scott Smith
   assert (dayOfWeek (SUNDAY,    FALSE, 10, 24) == SUNDAY);
   assert (dayOfWeek (WEDNESDAY, TRUE,  12, 21) == FRIDAY);
   assert (dayOfWeek (FRIDAY,    FALSE, 7 , 12) == SATURDAY);

   assert (dayOfWeek (THURSDAY, TRUE, 10, 28) == MONDAY);

   //A test of negatives - Jack Fletcher
   //assert (dayOfWeek (THURSDAY, FALSE, 3, 1) == WEDNESDAY);

   //#every possible date will be taken soon - Nathan Teoh
   assert(dayOfWeek (THURSDAY,   FALSE,  3, 31) == SUNDAY);
   assert(dayOfWeek (WEDNESDAY,  TRUE,   1, 28) == SATURDAY);

   //Jacob Tsagaris - My Birthday 2013 (18 Keen!!)
   assert (dayOfWeek (THURSDAY,TRUE, 5, 31) == FRIDAY);

   // My Brithday, SS
   assert (dayOfWeek (THURSDAY, FALSE, 8, 21) == WEDNESDAY);

   //WSY - Birthday
   assert (dayOfWeek (MONDAY, FALSE, 8, 1) == MONDAY);

   // pmky - birthday
   assert (dayOfWeek (SATURDAY,  TRUE,   8,  14) == FRIDAY);

   // R.I.P Michael Jackson - Added by CS
   assert (dayOfWeek (SATURDAY, FALSE, 6, 25) == THURSDAY);

   // Tests by Tristan Muir
   // I wanted to be helpful and submit some good ones and I would
   // have done more but the group seems to have submitted a pretty
   // comprehensive list and my tests are probably already included.
   // Such is the price of being disorganized. I will improve Richard, I promise!
   assert (dayOfWeek (FRIDAY,    TRUE,   2, 29) == FRIDAY);
   assert (dayOfWeek (THURSDAY,  TRUE,   3, 30) == SATURDAY);
   assert (dayOfWeek (THURSDAY,  TRUE,   1,  3) == WEDNESDAY);



   printf ("all tests passed - You are awesome!\n");
   return EXIT_SUCCESS;
}


// given the doomsday for a year, and whether or not it is a
// leap year, this function return the day of the week for any
// given month and day in the year.

int dayOfWeek (int doomsday, int leapYear, int month, int day) {
   int dayOfWeek;

   if (month == 1) {                                      // The following condition statements execute depending on the month. They
                                                          // then add the day of the month to the doomsday and subtract the date of
      if (leapYear == TRUE) {                             // the first doomsday of the month to get the day in terms of the first day
                                                          // of the month. This is then reduced (mod 7) to a number 0 to 6. Which
         dayOfWeek = (doomsday + day + 3) % 7;            // will be returned at the end of the function (as the dayOfWeek variable).
                                                          // In the case of January and February, an extra condition is required to
      } else {                                            // determine the first day of the month based on whether or not it is a
                                                          // leap year.
         dayOfWeek = (doomsday + day + 4) % 7;

      }
   } else if (month == 2) {

      if (leapYear == TRUE) {

         dayOfWeek = (doomsday + day + 6) % 7;

      } else {

         dayOfWeek = (doomsday + day) % 7;
      }
   } else if (month == 3) {

      dayOfWeek = (doomsday + day) % 7;

   } else if (month == 4) {

      dayOfWeek = (doomsday + day + 3) % 7;

   } else if (month == 5) {

      dayOfWeek = (doomsday + day + 5) % 7;

   } else if (month == 6) {

      dayOfWeek = (doomsday + day + 1) % 7;

   } else if (month == 7) {

      dayOfWeek = (doomsday + day + 3) % 7;

   } else if (month == 8) {

      dayOfWeek = (doomsday + day + 6) % 7;

   } else if (month == 9) {

      dayOfWeek = (doomsday + day + 2) % 7;

   } else if (month == 10) {

      dayOfWeek = (doomsday + day + 4) % 7;

   } else if (month == 11) {

      dayOfWeek = (doomsday + day) % 7;

   } else if (month == 12) {

      dayOfWeek = (doomsday + day + 2) % 7;

   }

   return (dayOfWeek);
}
