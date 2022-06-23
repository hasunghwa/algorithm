import sys
sys.stdin.readline

def search(R, S):
  F = R[0]
  for i in range(len(S)):
    if S[i] == F:
      A = ''
      B = ''
      if len(R) + i > len(S):
        A = S[i:]
        B = S[:len(R)-len(A)]
      else:
        A = S[i:i+len(R)]   
        
      if A + B == R:
        return True
  return False

R = input()
N = int(input())
cnt = 0

for _ in range(N):
  S = input()
  if search(R, S):
    cnt += 1
    
print(cnt)