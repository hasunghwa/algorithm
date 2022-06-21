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
    if self.count == 0:
      node = Node(x)
      self.head = node
      self.tail = node
    else:
      node = Node(x)
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

  def empty(self):
    if self.count == 0:
      return True
    else:
      return False

def cal(n):
  yield ("D", 2 * n if 2 * n < 10000 else (2 * n) % 10000)
  yield ("S", n - 1 if n != 0 else 9999)
  yield ("L", (n % 1000)*10 + (n//1000))
  yield ("R", (n % 10)*1000 + (n//10))

T = int(input())

for _ in range(T):
  A, B = map(int, input().split())
  path = [""]*10001  # 경로파악

  q = Queue()
  q.push(A)

  path[A] = "start"
  
  while q:
    n = q.pop()
    if n == B:
      print(path[B][5:])  # start 빼고
      break
    
    for cmd, res in cal(n):
      if path[res]:
        continue

      path[res] = path[n] + cmd
      q.push(res)
