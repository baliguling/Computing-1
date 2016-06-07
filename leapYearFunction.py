GREGORIAN_CALENDAR = 1582

def isLeapYear(LYear):
	if LYear%400 == 0:
		return 1

	elif LYear%4==0 & year%100 !=0:
		return 1

	else:
	 	return 0

myYear = int(input('please enter the year you are interested in: '))
assert myYear >= GREGORIAN_CALENDAR

if isLeapYear(myYear) == 1:
	print(str(myYear) + " is a leap year!\n")

elif isLeapYear(myYear) == 0:
	print(str(myYear) + " is a not leap year!\n")
