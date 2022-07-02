import sys
input = sys.stdin.readline

T = int(input())

for _ in range(T):
  N = int(input())
  start = []
  startW = 0
  endW = 0
  cnt = 0
  diff = 0

  for c in input().strip():
    if c == 'W':
      startW += 1
    start.append(c)

  i = 0
  for c in input().strip():
    if c == 'W':
      endW += 1
    if start[i] != c:
      diff += 1
    i += 1

  cnt += startW - endW if startW > endW else endW - startW
  diff -= cnt
  cnt += diff // 2

  print(cnt)

  # W를 늘리고, 줄이고 그만큼 diff 빼고 diff // 2?
