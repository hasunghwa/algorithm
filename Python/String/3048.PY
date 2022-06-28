N, N2 = map(int, input().split())

group = input()
group2 = input()
T = int(input())
if T == 0:
  print(group[::-1] + group2)
  exit()
  
arr = [1] * len(group) + [0] * len(group2)

for _ in range(T):
  i = 0
  while i < len(arr)-1:
    if arr[i] > arr[i+1]:
      arr[i] = 0
      arr[i+1] = 1
      i+=1
    i+=1

result = ''
i = len(group)
j = 0
for c in arr:
  if c == 1:
    result += group[i-1]
    i -= 1
  else:  
    result += group2[j]
    j += 1

print(result)