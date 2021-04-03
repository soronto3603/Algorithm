function solution(needs, r) {
  let countRobot = r
  let result = 0

  const dict = {}
  const b = new Array(needs[0].length).fill(0)

  for (const need of needs) {
    dict[`${need}`] = dict[`${need}`] ? dict[`${need}`] + 1 : 1
  }
  for (const [key, value] of Object.keys(dict).map(key => [key, dict[key]]).sort((a, b) => b[1] - a[1])) {
    console.log(key, b)
    const needUnitList = key.split(',').map((value, index) => {
      if (b[index] === 1 && +value === 1) {
        return 0
      }
      return value
    })

    console.log(needUnitList)

    if (needUnitList.filter(unit => +unit !== 0).length > countRobot) {
      break
    }

    for (const [index, needUnit] of Object.entries(needUnitList)) {
      console.log(index, needUnit)
      if (+needUnit === 1) {
        b[index] = 1
        countRobot--
      }
    }
    result += value
  }
  console.log(result)
  return result
}

console.log(solution([ [ 1, 0, 0 ], [1, 1, 0], [1, 1, 0], [1, 0, 1], [1, 1, 0], [0, 1, 1] ], 2) === 4)
// console.log(solution([5, 4, 5, 4, 5], [1, 2, 3, 5, 4]) === 3)


