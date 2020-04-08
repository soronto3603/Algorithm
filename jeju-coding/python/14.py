import random

rand = random.randrange(0, 1000)
print(rand)

if rand % 3 == 0:
  print('짝')
else:
  print(rand)