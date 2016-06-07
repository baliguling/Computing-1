def printWondrous (start):
    count = 1
    while start != 1:
        if (start % 2) == 0:
            start = start/2
        else:
            start = start * 3 + 1
        print (str(start),end=" ")
        count = count + 1
    return count

start = int(input('Enter start number:'))
print (str(start),end=" ")
printWondrous(start)

