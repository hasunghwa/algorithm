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
    
N, M = map(int, input().split())
space = [[0 for i in range(M)] for j in range(N)]

for y in range(N):
  temp = input()
  for x in range(M):
    space[y][x] = int(temp[x])

move = [[-1,0], [1,0], [0,-1], [0,1]]
q = Queue()
q.push([0, 0])
vis = [[0 for i in range(M)] for j in range(N)]

while q.count > 0:
  cur = q.pop()
  y, x = cur[0], cur[1]
  
  for dy, dx in move:
    moveY, moveX = dy+y, dx+x
    if 0 <= moveY < N and 0 <= moveX < M and space[moveY][moveX] != 0 and vis[moveY][moveX] != 1:
      q.push([moveY, moveX])
      space[moveY][moveX] = space[y][x] + 1
      vis[moveY][moveX] = 1

print(space[N-1][M-1])