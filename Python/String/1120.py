import sys
input = sys.stdin.readline

def diff(A, B):
  cnt = 0
  for i in range(len(A)):
    if A[i] != B[i]:
      cnt += 1
  return cnt

A, B = map(str, input().split())

lenDiff = len(B) - len(A)
min = len(B)
for i in range(lenDiff + 1):
  cnt = diff(B[:i] + A + B[len(A) + i:], B)
  min = cnt if min > cnt else min
  
print(min)