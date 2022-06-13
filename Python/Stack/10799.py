line = input()
ans = 0
stack = []

for i in range(len(line)):
  if line[i] == "(":
    stack.append(line[i])
  else:
    if line[i-1] == "(":
      stack.pop()
      ans += len(stack)
    else:
      stack.pop()
      ans += 1
    
print(ans)