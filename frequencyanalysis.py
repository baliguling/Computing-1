from string import ascii_lowercase
from string import ascii_uppercase
from collections import Counter

with open('text.txt') as f:
    print Counter(letter for line in f 
                  for letter in line.lower() 
                  if letter in ascii_lowercase, ascii_uppercase)
