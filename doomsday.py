THURSDAY = 0
FRIDAY =  1
SATURDAY = 2
SUNDAY =  3
MONDAY  = 4
TUESDAY = 5
WEDNESDAY = 6

TRUE = 1
FALSE = 0
DAYS_PER_WEEK = 7

def dayOfWeek (doomsday, leapYear, month, day):
   int(dayOfWeek)

   if month == 1:
     if leapYear == FALSE:
        dayOfWeek = (abs(doomsday + day - 3)) % DAYS_PER_WEEK
     else:
        dayOfWeek = (abs(doomsday + day - 4)) % DAYS_PER_WEEK
   
   elif month == 2:
     if leapYear == FALSE:
        dayOfWeek = (abs(doomsday + day - 28)) % DAYS_PER_WEEK
     else:
        dayOfWeek = (abs(doomsday + day - 29)) % DAYS_PER_WEEK
   
   elif (month == 3):
     dayOfWeek = (abs(doomsday + day - 7)) % DAYS_PER_WEEK
   
   elif (month == 4):
     dayOfWeek = (abs(doomsday + day - 4)) % DAYS_PER_WEEK
   
   elif (month == 5):
     dayOfWeek = (abs(doomsday + day - 2)) % DAYS_PER_WEEK
   
   elif (month == 6):
     dayOfWeek = (abs(doomsday + day - 6)) % DAYS_PER_WEEK
   
   elif (month == 7):
     dayOfWeek = (abs(doomsday + day - 4)) % DAYS_PER_WEEK
   
   elif (month == 8):
     dayOfWeek = (abs(doomsday + day - 1)) % DAYS_PER_WEEK
   
   elif (month == 9):
     dayOfWeek = (abs(doomsday + day - 5)) % DAYS_PER_WEEK
   
   elif (month == 10):
     dayOfWeek = (abs(doomsday + day - 3)) % DAYS_PER_WEEK
   
   elif (month == 11):
     dayOfWeek = (abs(doomsday + day - 7)) % DAYS_PER_WEEK
   
   elif (month == 12):
     dayOfWeek = (abs(doomsday + day - 5)) % DAYS_PER_WEEK
   

   return dayOfWeek

def main():
  assert dayOfWeek (THURSDAY,  FALSE,  4,  4) == THURSDAY
  assert dayOfWeek (FRIDAY,    FALSE,  6,  6) == FRIDAY
  assert dayOfWeek (MONDAY,    FALSE,  8,  8) == MONDAY
  assert dayOfWeek (WEDNESDAY, FALSE, 10, 10) == WEDNESDAY
  assert dayOfWeek (FRIDAY,    FALSE, 12, 12) == FRIDAY
  assert dayOfWeek (THURSDAY,  FALSE,  9,  5) == THURSDAY
  assert dayOfWeek (FRIDAY,    FALSE,  5,  9) == FRIDAY
  assert dayOfWeek (SUNDAY,    FALSE,  7, 11) == SUNDAY
  assert dayOfWeek (TUESDAY,   FALSE, 11,  7) == TUESDAY
  assert dayOfWeek (WEDNESDAY, FALSE,  3,  7) == WEDNESDAY
  assert dayOfWeek (THURSDAY,  FALSE,  4,  5) == FRIDAY
  assert dayOfWeek (SATURDAY,  FALSE,  6,  5) == FRIDAY
  assert dayOfWeek (MONDAY,    FALSE,  8,  9) == TUESDAY
  assert dayOfWeek (WEDNESDAY, FALSE, 10,  9) == TUESDAY
  assert dayOfWeek (FRIDAY,    FALSE, 12, 20) == SATURDAY
  assert dayOfWeek (THURSDAY,  FALSE,  9,  9) == MONDAY
  assert dayOfWeek (FRIDAY,    FALSE,  5,  5) == MONDAY
  assert dayOfWeek (SUNDAY,    FALSE,  7,  7) == WEDNESDAY
  assert dayOfWeek (TUESDAY,   FALSE, 11, 11) == SATURDAY
  assert dayOfWeek (THURSDAY,  FALSE,  3, 30) == SATURDAY
  assert dayOfWeek (TUESDAY,   FALSE,  2,  28) == TUESDAY
  assert dayOfWeek (TUESDAY,   FALSE,  2,  27) == MONDAY
  assert dayOfWeek (THURSDAY,  FALSE,  1,  3)  == THURSDAY
  printf ("all tests passed - You are awesome!\n");
   