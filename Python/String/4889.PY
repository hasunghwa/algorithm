import sys
input = sys.stdin.readline

def changeCount(T):
  stack = []
  cnt = 0
  for c in T:
    if c == '{':
      stack.append('{')
    else:
      if stack and stack[len(stack)-1] == '{':
        stack.pop()
      else:
        stack.append('{')
        cnt += 1
  return cnt + len(stack)//2

case = 1
while(T := input()[:-1])[0] != '-':
  print(f'{case}. {changeCount(T)}')
  case += 1
