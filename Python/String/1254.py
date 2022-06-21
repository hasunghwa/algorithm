import sys
input = sys.stdin.readline

def reverse(S):
  R = ''
  for c in range(len(S)-1, -1, -1):
    R += S[c]
  return R

S = input()[:-1]
if S != reverse(S):
  P = S
  cnt = 0
  add = S[cnt]

  while(1):
    P += reverse(add)
    if P == reverse(P):
      break
    cnt += 1
    add += S[cnt]
    P = S

  print(len(P))
else:
  print(len(S))
