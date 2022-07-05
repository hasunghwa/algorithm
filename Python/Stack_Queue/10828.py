import sys
input = sys.stdin.readline

num = int(input())
n = -1
arr = []

for _ in range(num):
  cmd = list(input().split())

  if(cmd[0] == "push"):
    n += 1
    arr.append(int(cmd[1]))
  elif(cmd[0] == "pop"):
    if n == -1:
      print(-1)
    else:
      print(arr[n])
      n -= 1
      arr.pop()
  elif(cmd[0] == "size"):
    print(len(arr))
  elif(cmd[0] == "empty"):
    print(1) if n == -1 else print(0)
  elif(cmd[0] == "top"):
    print(arr[n]) if n != -1 else print(n)
