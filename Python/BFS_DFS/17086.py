import sys
input = sys.stdin.readline

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

space = [list(map(int, input().split())) for _ in range(N)]
move = [[-1, -1], [-1, 0], [-1, 1], [0, -1], [0, 1], [1, -1], [1, 0], [1, 1]]

q = Queue()
for y in range(N):
    for x in range(M):
        if space[y][x] == 1:
            q.push([y, x])

MAX = 0
def BFS():
  global MAX    
  while q.count > 0:
    cur = q.pop()
    curY, curX = cur[0], cur[1]    
    for dy, dx in move:
      moveY, moveX = curY + dy, curX + dx
      if 0 <= moveY < N and 0 <= moveX < M and space[moveY][moveX] == 0:
        space[moveY][moveX] = space[curY][curX]+1
        q.push([moveY, moveX])
        if MAX < space[moveY][moveX]:
            MAX = space[moveY][moveX]
        
  return MAX-1
print(BFS())
print(space)
