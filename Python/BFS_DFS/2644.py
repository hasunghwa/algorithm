class Node():
  def __init__(self, data):
    self.data = data
    self.next = None

class Queue():
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
      return False
    else:
      node = self.head
      self.head = node.next
      self.count -= 1
      return node.data

n = int(input())
A, B = map(int, input().split())
m = int(input())

family = [[] for _ in range(n+1)]
for _ in range(m):
  x, y = map(int, input().split())
  family[x].append(y)

ans = 100
for idx in range(n+1):
  cnt = 0 if idx == A else -1
  cnt1 = 0 if idx == B else -1
  
  for F in family[idx]:
    q = Queue()
    q.push([F, 1])
    while q.count > 0:
      cur = q.pop()
      
      if cur[0] == A:
        cnt = cur[1]
      if cur[0] == B:
        cnt1 = cur[1]
      
      if cnt != -1 and cnt1 != -1:
        ans = cnt+cnt1 if ans > cnt + cnt1 else ans
        
      for c in family[cur[0]]:
        q.push([c, cur[1]+1])
        
print(ans if ans != 100 else -1)