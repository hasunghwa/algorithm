N, B = map(str, input().split())
B = int(B)
ans = 0
square = 1
for i in range(len(N), 0, -1):
  ans += int(N[i-1]) * square if ord(N[i-1]) < 58 else (ord(N[i-1])-55) * square 
  square *= B
print(ans)
