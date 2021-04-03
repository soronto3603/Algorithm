function insert(array, index, value) {
  return array.slice(0, index).concat(value).concat(array.slice(index, array.length))
}

function deleteItem(array, index) {
  return array.slice(0, index).concat(array.slice(index + 1, array.length))
}

function solution(operations) {
  const DELETE_MAX = 'D 1'
  const DELETE_MIN = 'D -1'

  let q = []
  for (const operation of operations) {
    if (operation === DELETE_MAX) {
      q = deleteItem(q, q.length - 1)
    } else if (operation === DELETE_MIN) {
      q = deleteItem(q, 0)
    } else {
      const number = +operation.split(' ')[1]
      const qMax = q[q.length - 1]
      if (q.length === 0) {
        q.push(number)
        continue
      }
      if (number > qMax) {
        q = insert(q, q.length, number)
        continue
      }
      for (let i=0;i<q.length;i++) {
        if (number < q[i]) {
          q = insert(q, i, number)
          break
        }
      }
    }
  }

  if (q.length === 0) {
    return [0, 0]
  } else if (q.length === 1) {
    return [q[0], q[0]]
  } else {
    return [q[q.length - 1], q[0]]
  }
}

function check(solutionFunction, input, result) {
  console.log(input, JSON.stringify(solutionFunction(input)) === JSON.stringify(result))
  return JSON.stringify(solutionFunction(input)) === JSON.stringify(result)
}

check(solution, ["I 16","D 1"], [0,0])
check(solution, ["I 7","I 5","I -5","D -1"], [7,5])
