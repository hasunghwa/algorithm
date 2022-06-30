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
M = int(input())

space = [[0 for i in range(N)] for j in range(N)]
ans = 0

for _ in range(M):
  A, B = map(int, input().split())
  space[A-1][B-1] = 1
  space[B-1][A-1] = 1
  
vis = [0 for i in range(N)]
for i in range(N):
  if space[0][i] != 1:
    continue
  q = Queue()
  q.push([0, i])
  if vis[i] != 1:
    vis[i] = 1
    ans += 1
  
  while q.count > 0:
    vi = q.pop()
    y, x = vi[0], vi[1]
    
    for j in range(N):
      if space[x][j] == 1 and vis[j] != 1:
        q.push([x, j])
        vis[j] = 1
        ans += 1
        
print(ans-1)