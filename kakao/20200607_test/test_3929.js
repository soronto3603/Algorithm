function solution(v) {
  const dictX =  v.reduce((dict, pos) => {
    const [x, y] = pos
    dict[x] = dict[x] ? dict[x] + 1 : 1
    return dict
  }, {})

  const dictY =  v.reduce((dict, pos) => {
    const [x, y] = pos
    dict[y] = dict[y] ? dict[y] + 1 : 1
    return dict
  }, {})

  return [
    +Object.entries(dictX).filter(row => row[1] === 1)[0][0],
    +Object.entries(dictY).filter(row => row[1] === 1)[0][0]
  ]
}

let answer = null
answer = solution([[1, 4], [3, 4], [3, 10]])
console.log(JSON.stringify(answer) === JSON.stringify([1, 10]))

answer = solution([[1, 1], [2, 2], [1, 2]])
console.log(JSON.stringify(answer) === JSON.stringify([2, 1]))
