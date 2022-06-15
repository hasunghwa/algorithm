import sys
input = sys.stdin.readline

def continuous(num):
  count = 1
  max = -1
  for i in range(1, len(num)):
    if num[i] == num[i-1]:
      count += 1
    else:
      max = max if max > count else count
      count = 1
  return max if max > count else count

while(line := input()[:-1]):
  print(continuous(line))
