// 다익스트라 맥스


function solution(n, passenger, train) {
  const MAX = 200001
  const nodes = new Array(n).fill(null).map((_, index) => index)
  const distances = new Array(n).fill(MAX)
  const S = [0]

  let currentIndex = 0
  let currentNode = nodes[currentIndex]
  distances[currentIndex] = 0

  for (const [src, dest] of train) {
    if (src === 1) {
      distances[dest - 1] = passenger[dest - 1]
    }
  }
  while (S.length !== nodes.length) {
    // S 가 아니면서 제일 작은 노드
    const notSNodes = nodes.filter(node => {
      if (S.find(passed => passed === node) !== undefined || distances[node] === MAX) {
        return false
      }
      return true
    })


    const sortedNotSPaths = notSNodes.map(node => [node, distances[node]]).sort((a, b) => a[1] - b[1])
    const lowCost = sortedNotSPaths[0]

    // 선정됨
    lowCost

    S.push(lowCost[0])

    for (const [src, dest] of train) {
      if (src - 1 === lowCost[0]) {
        if (distances[dest - 1] === MAX) {
          distances[dest - 1] = distances[lowCost[0]] + passenger[dest - 1]
        }
      }
    }

    // break
  }
  // console.log(currentNode)
  const dist = Math.max(...distances)
  const [node, p] = distances.map((distance, index) => [index, distance]).filter(([index, distance]) => distance === dist).sort((a, b) => b[0] - a[0])[0]
  return [node + 1, p + passenger[0]]
}


function equal(array1, array2) {
  return JSON.stringify(array1) === JSON.stringify(array2)
}

// console.log(solution(6,[1,1,1,1,1,1],[[1,2],[1,3],[1,4],[3,5],[3,6]]) === [6,3])
// console.log(solution(4,[2,1,2,2],[[1,2],[1,3],[2,4]]) === [4,5])
console.log(equal(solution(6,[1,1,2,3,4,4],[[1,2],[1,3],[1,4],[1,5],[1,6]]) === [5,5]))