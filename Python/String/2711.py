N = int(input())

def erase(location, string):
  return string[:location-1] + string[location:]

for i in range(N):
  line = input()
  location = int(line.split()[0])
  string = line.split()[1]
  print(erase(location, string))
