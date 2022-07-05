import sys
input = sys.stdin.readline

def check (line):
  stack = []
  for c in line:
    if c == "[" or c == "(":
      stack.append(c)
    if c == "]":
      if not stack or stack.pop() != "[":
        return "no"
    if c == ")":
      if not stack or stack.pop() != "(":
        return "no"
      
  if len(stack) > 0:
    return "no"
  return "yes"

# while (line := input().replace('\n', '')) != '.':
while (line := input()[:-1]) != '.':
  print(check(line))
