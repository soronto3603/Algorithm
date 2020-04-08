planets = ['수성', '금성', '지구', '목성', '토성', '천왕성', '해왕성']

n = input()
try:
  print(planets[int(n) - 1])
except:
  print('존재하지 않는 숫자')