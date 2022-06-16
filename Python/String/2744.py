import sys
input = sys.stdin.readline

line = input()
ans = ''
for i in range(len(line)-1):
  ans += chr(ord(line[i]) + 32) if line[i] < 'Z' else chr(ord(line[i]) - 32)
  
print(ans)