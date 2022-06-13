import sys
input = sys.stdin.readline

class Node:
  def __init__(self, data, next):
    self.data = data
    self.next = None
    
class Stack:
  def __init__(self):
    self.topIt = None
    self.count = 0
    
  def push(self, x):
    self.topIt = Node(x, self.topIt)
    self.count += 1
    
  def pop(self):
    if not self.isEmpty():
      node = self.topIt
      self.topIt = node.next
      self.count -= 1
      print(node.data)
    else :
      print(-1)
  
  def size(self):
    print(self.count)
    
  def isEmpty(self):
    return (self.count == 0)
  
  def top(self):
    if not self.isEmpty():
      print(self.topIt.data)
    else :
      print(-1)

  def empty(self):
    if not self.isEmpty():
      print(0)
    else:
      print(1)

num = int(input())
stack = Stack()

for i in range(num):
  cmd = list(input().split())
  if (cmd[0] == 'top'):
    stack.top()
  elif (cmd[0] == 'size'):
    stack.size()
  elif (cmd[0] == 'empty'):
    stack.empty()
  elif (cmd[0] == 'pop'):
    stack.pop()
  else:
    stack.push(int(cmd[1]))
