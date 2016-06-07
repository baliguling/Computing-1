GREGORIAN_CALENDAR = 1582

myYear = int(input('please enter the year you are interested in: '))
assert myYear >= GREGORIAN_CALENDAR

if myYear%400 == 0:
    print(str(myYear) + " is a leap year!\n")

elif myYear%4==0 & year%100 !=0:
    print(str(myYear) + " is a leap year!\n")

else:
    print (str(myYear) + " is not a leap year!")
