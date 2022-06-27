def merge(left, right):
  sorted = []
  i = 0
  j = 0
  while len(left) > i and len(right) > j:
    if left[i] < right[j]:
      sorted.append(left[i])
      i += 1
    else:
      sorted.append(right[j])
      j += 1
      
  if len(left) == i:
    sorted += right[j:]
  elif len(right) == j:
    sorted += left[i:]
  return sorted

def merge_sort(arr):  
  if len(arr) <= 1: return arr
  mid = len(arr) // 2
  left = merge_sort(arr[:mid])
  right = merge_sort(arr[mid:])
  return merge(left, right)
  
N = int(input())
num = []
for _ in range(N):
  content = input() 
  tmp = ''
  for c in content:
    if ord(c) >= ord('a') and tmp != '':
      num.append(int(tmp))
      tmp = ''
    elif ord(c) < ord('a'):
      tmp += c
  if tmp != '':
    num.append(int(tmp))

for c in merge_sort(num):
  print(c)

