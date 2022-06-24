import sys
input = sys.stdin.readline

vowels = ['a', 'e', 'i', 'o', 'u']
while(pw := input()[:-1]) != 'end':
  prev = ''
  isOK = 'not '
  vCnt = 0
  cCnt = 0
  
  for c in pw:
    if c in vowels: # 모음
      vCnt += 1
      cCnt = 0
      isOK = ''
    else: # 자음
      cCnt += 1
      vCnt = 0
      
    if vCnt == 3 or cCnt == 3: # 모음 자음 연속      
      isOK = 'not '
      break    
    
    if prev == c: # 같은글자 연속
      if c != 'e' and c != 'o':
        isOK = 'not '
        break
    
    prev = c
  print(f'<{pw}> is {isOK}acceptable.')
