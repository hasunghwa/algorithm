S = input()
min = 'z' * len(S)

for i in range(1, len(S) - 1):
  for j in range(i+1, len(S)):
    split = [S[:i][::-1], S[i:j][::-1], S[j:][::-1]]
    if ''.join(split) < min:
      min = ''.join(split)
      
print(min)