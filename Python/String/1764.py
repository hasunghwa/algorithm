import sys
input = sys.stdin.readline

def merge(left, right):
  sorted = []
  i = 0
  j = 0
  
  while (i < len(left) and j < len(right)):
    if left[i] < right[j]:
      sorted.append(left[i])
      i += 1
    else:
      sorted.append(right[j])
      j += 1
    
  if i == len(left):
    sorted += right[j:]
  else:
    sorted += left[i:]

  return sorted

def merge_sort(arr):
  if len(arr) <= 1: return arr
  mid = len(arr) // 2
  left = merge_sort(arr[:mid])
  right = merge_sort(arr[mid:])
  return merge(left, right)


N, M = map(int, input().split())
nameList = [input()[:-1] for _ in range(N)]
ans = []
cnt = 0

for _ in range(M):
  see = input()[:-1]
  nameList.append(see)

sortList = merge_sort(nameList)
tmp = sortList[0]

for i in range(1, len(nameList)):
  if tmp == sortList[i]:
    ans.append(tmp)
    cnt += 1
  else:
    tmp = sortList[i]
  
print(cnt)
for name in ans:
  print(name)
