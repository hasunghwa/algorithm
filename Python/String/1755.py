M, N = map(int, input().split())

eng = [9, 4, 8, 7, 2, 1, 6, 5, 0, 3]
store = {}
for i in range(M, N + 1):
  n = 0
  if i >= 1 and i <= 9:
    n = eng[i] * 10
  
  else:
    n = eng[i // 10] * 10 + eng[i % 10]
  store[i] = n
  
sortStore = sorted(store.items(), key=lambda x: x[1])
cnt = 1

for i in dict(sortStore).keys():
  print(i, end = ' ')
  if cnt % 10 == 0:
    print()
  cnt += 1