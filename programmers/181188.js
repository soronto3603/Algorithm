function range(a, b) {
  return [...new Array(b - a + 1).keys()].map((v) => v + a);
}

function solution(targets) {
  let system = [0, 0]
  const sorted = targets.sort((a, b) => a[0] - b[0]);
  for (const target of sorted) {
    if ((system[0] <= target[0] && system[1] > target[1]) &&)
  }
  
}

console.log(
  solution([
    [4, 5],
    [4, 8],
    [10, 14],
    [11, 13],
    [5, 12],
    [3, 7],
    [1, 4],
  ]) === 3
);
