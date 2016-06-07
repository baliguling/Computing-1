first, second, third = int(input("Enter 3 numbers: ").split())
if first<third & first<second:
    print(str(first)
elif second<third & second<first:
    print(str(second))
else:
    print(str(third))

if first<third & first>second:
    print (str(first))
elif first>third & first<second:
    print (str(first))
elif second<third & second>first:
    print (str(second))
else:
    print (str(third))

if first>third & first>second:
    print (str(first))
elif second>third & second>first:
    print (str(second))
else:
    print (str(third))
