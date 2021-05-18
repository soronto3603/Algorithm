
function solution(nodeinfo) {
  const binaryTree = []

  for (const y of new Array(Math.max(...nodeinfo.map(node => node[1])) + 1).fill(null).map((_, index) => index).reverse()) {
    const founds = nodeinfo.filter(([x, _y]) => _y === y)
    console.log(founds)
  }

  // for (const node of nodeinfo) {
  //   binaryTree.push(node)
  // }
  return null
}

function stringEqual(object1, object2) {
  return JSON.stringify(object1) === JSON.stringify(object2)
}

console.log(stringEqual(solution([[5,3],[11,5],[13,3],[3,5],[6,1],[1,3],[8,6],[7,2],[2,2]]), [[7,4,6,9,1,8,5,2,3],[9,6,5,8,1,4,3,2,7]]))
