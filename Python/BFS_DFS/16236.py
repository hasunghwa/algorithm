class Node:
  def __init__(self, data):
    self.data = data
    self.next = None

class Queue:
  def __init__(self):
    self.head = None
    self.tail = None
    self.count = 0  
    
  def push(self, x):
    node = Node(x)
    if self.count == 0:
      self.head = node
    else:
      self.tail.next = node
      
    self.tail = node 
    self.count += 1
    
  def pop(self):  
    if self.count == 0:
      return -1
    else:
      node = self.head
      self.head = node.next
      self.count -= 1
      return node.data
    
N = int(input())

shark = [0, 0]
space = [[0 for i in range(N)] for j in range(N)]

for y in range(N):
  temp = input().split()
  for x in range(N):
    space[y][x] = int(temp[x])
    if space[y][x] == 9:
      shark[0], shark[1] = y, x

ans = 0  # 시간 저장
shark_size = 2  # 상어 size
cnt = 0  # 상어가 현재 size에서 몇 마리를 먹엇는지 저장하는 변수
move = [(-1, 0), (0, -1), (0, 1), (1, 0)]

while True:
  visited = [[0 for i in range(N)] for j in range(N)]
  visited[shark[0]][shark[1]] = 1
  q = Queue()
  q.push(shark+[0])
  target = [-1, -1, 0]
  
  while q.count > 0:
    cur = q.pop()
    curY, curX, curT = cur[0], cur[1], cur[2]
    
    if curT > target[2] and target[2] != 0:
      break
    
    if 0 < space[curY][curX] < shark_size and space[curY][curX] != 9:
      if target[2] == 0:
        target = cur
      else:
        if curY < target[0]:
          target = cur
        elif curY == target[0] and curX < target[1]:
          target = cur
      
    for dy, dx in move:
      moveY, moveX = curY + dy, curX + dx
      if 0 <= moveX < N and 0 <= moveY < N and space[moveY][moveX] <= shark_size and visited[moveY][moveX] != 1:
        q.push([moveY, moveX, curT+1])
        visited[moveY][moveX] = 1
  
  if target[0] == -1 and target[1] == -1:
    break
  
  if cnt+1 == shark_size:
    cnt, shark_size = 0, shark_size+1
  else:
    cnt += 1
    
  space[shark[0]][shark[1]] = 0
  space[target[0]][target[1]] = 9
  ans += target[2]
  shark = [target[0], target[1]]
  
print(ans)
