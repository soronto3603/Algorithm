function display(N, map) {
  for (let i=0; i<N;i++) {
    let row = ''
    for (let j=0;j<N;j++) {
      row += map[i][j] + ' '
    }
    console.log(row)
  }
}
function solution(N, facility) {
  const map = Array(N).fill(-1).map(_ => Array(N).fill(-1))
  const [x, y, v] = facility
  for (let i=1; i<N + 1;i++) {
    for (let j=1;j<N + 1;j++) {
      const distancesMax = facility.map(f => (Math.abs(i - f[0]) + Math.abs(j - f[1])) * f[2]).reduce((a, b) => a > b ? a : b)
      map[i - 1][j - 1] = distancesMax
    }
  }
  const min = map.reduce((p, c) => p.concat(c)).reduce((a, b) => a > b ? b : a)
  return min
}
// solution(3, [[1,3,1],[3,1,1]])
solution(3, [[1,3,2],[3,1,1]])
// solution(3, [[1,1,1]])