import sys
input = sys.stdin.readline
trees = {}
cnt = 0
while(line:= input()[:-1]):
  cnt += 1
  if line in trees:
    trees[line] += 1
  else:
    trees[line] = 1

for tree in sorted(trees.items()):
  print(f'{tree[0]}{tree[1]/cnt * 100: .4f}')