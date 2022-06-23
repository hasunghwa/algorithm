import sys


import sys
input = sys.stdin.readline
N, M = map(int, input().split())

DNAS = [[] for _ in range(N)]
ans = ''
HD = 0

for i in range(N):
  DNA = input()[:-1]
  DNAS[i] = DNA

for i in range(M):
  tmp = {'T': 0, 'A': 0, 'G': 0, 'C': 0}
  for j in range(N):
    tmp[DNAS[j][i]] += 1
    
  sortedTmp = sorted(sorted(tmp.items()), key=lambda x: x[1], reverse=True)
  ans += sortedTmp[0][0]
  HD += N - sortedTmp[0][1]
  
print(f'{ans}\n{HD}')
