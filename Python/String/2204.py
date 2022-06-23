import sys
input = sys.stdin.readline

while(N := int(input())) != 0:
  ans = 'z' * N
  lowerAns = 'z' * N
  
  for _ in range(N):
    S = input()[:-1]
    if S.lower() < lowerAns:
      ans = S
      lowerAns = S.lower()
      
  print(ans)