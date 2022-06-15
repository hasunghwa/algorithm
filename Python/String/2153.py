def change(word):
  num = 0
  for c in word:
    num += ord(c)-96 if ord(c) >= 97 else ord(c)-38
  return num

def isDecimal(num):
  for i in range(2, num):
    if num % i == 0:
      return 'It is not a prime word.'
  return 'It is a prime word.'

word = input()
print(isDecimal(change(word)))
