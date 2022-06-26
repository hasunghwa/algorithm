name = input()

alpabat = [0] * 26
cnt = 0
head = ''
center = ''

for c in name:
  alpabat[ord(c)-65] += 1

for c in alpabat:
  if c % 2 != 0:
    cnt += 1
  if cnt > 1:
    print('I\'m Sorry Hansoo')
    exit()

for i, cnt in enumerate(alpabat):
  head += chr(i+65) * (cnt // 2)
  alpabat[i] = cnt % 2
  
  if cnt % 2 != 0:     
    center += chr(i+65)
    alpabat[i] -= 1
    
print(head + center + head[::-1])

# N짝수 다 짝수여야됨
# N홀수 하나 홀수 나머지 짝수 (홀수가 가운데로)