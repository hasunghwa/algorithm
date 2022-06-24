def check(arr, x):
  for i in range(x+1, len(arr)):
    if arr[i] > 0:
      return i
  return -1

X = input()
min = 999999

for i in range(len(X)-1):
  arr = [0] * 10
  for n in X:
    arr[int(n)] += 1
    
  num = ''
  for j in X[:i]:
    num += j
    arr[int(j)] -= 1
  
  isBig = check(arr, int(X[i]))
  if isBig == -1:
    continue
  
  arr[isBig] -= 1
  num += str(isBig)
  
  for i in range(len(arr)):
    while(arr[i] > 0):
      num += str(i)
      arr[i] -= 1
      
  if int(num) > int(X):
    min = int(num) if min > int(num) else min
    
print(min if min != 999999 else 0)