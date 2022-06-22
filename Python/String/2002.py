import sys
input = sys.stdin.readline

N = int(input())

result = 0
cars = {}
nextCar = ''

for i in range(N):
  carNum = input()[:-1]

  if i == 0:
    nextCar = carNum
    
  cars[carNum] = i + 1 

for i in range(N):
  carNum = input()[:-1]
  
  if nextCar != carNum:
    cars[carNum] = 0
    result += 1
  
  else:
    cars[carNum] = 0
    for k in cars.keys():
      if cars[k] != 0:
        nextCar = k
        break
    
print(result)