import sys
input = sys.stdin.readline

def count(word, sentence):
  ans = 0
  for c in sentence:
    if c == word:
      ans += 1
  return ans

while (line := input()[:-1]) != '#':
  word = line.split()[0]
  sentence = "".join(line.split()[1:]).lower()
  print(word, count(word, sentence))
