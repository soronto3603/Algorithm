def solution(routes):
  answer = 0

  while(len(routes)>0):
    distances = [i[1]-i[0] for i in routes]
    min_index = distances.index(min(distances))
    distances[min_index] = 0

    answer+=1
    a = routes[min_index]
    del routes[min_index]

    for b in routes:
      if (a[0] > b[0] and a[1] < b[1]) or (a[0] < b[0] and b[0] < a[1]) or (b[0] < a[0] and b[1] < a[0]):
        del routes[routes.index(b)]
      else:
        pass
  return answer

print(solution([[-20,15], [-14,-5], [-18,-13], [-5,-3]]))