import sys
input = sys.stdin.readline

def sum(S):
  ans = 0
  char = [0] * 26
  for i in S:
    char[ord(i)-65] = 1
  
  for i in range(len(char)):
    if char[i] == 0:
      ans += 65 + i
  return ans      
    
T = int(input())

for i in range(T):
  S = input()
  print(sum(S[:-1]))
