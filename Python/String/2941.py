import sys
input = sys.stdin.readline

line = input()
ans = 0
i = 0
while len(line)-1  > i:
  if line[i:i+2] == 'c=' or line[i:i+2] == 'c-':
    ans += 1
    i += 2
  elif line[i:i+2] == 'd-':
    ans += 1
    i += 2
  elif line[i:i+3] == 'dz=':
    ans += 1
    i += 3    
  elif line[i:i+2] == 'lj':
    ans += 1
    i += 2
  elif line[i:i+2] == 'nj':
    ans += 1
    i += 2
  elif line[i:i+2] == 's=':
    ans += 1
    i += 2
  elif line[i:i+2] == 'z=':
    ans += 1
    i += 2
  else: 
    ans += 1
    i += 1
print(ans)
# ljes=njak 6
# ddz=z= 3
# nljj 3
# c=c= 2
# dz=ak 3 