function solution(map) {
  const dragRect = {
    x1: 0,
    y1: 0,
    x2: 0,
    y2: 0,
  };

  const points = [];
  for (const col of Object.keys(map)) {
    for (const row of Object.keys(map[row])) {
      if (map[row][col] === "#") {
        points.push({ x: +col, y: +row });
      }
    }
  }

  for (const point of points) {
    // 포인트중 가장 왼쪽 끝
    dragRect.x1;
  }
}

console.log(stringEqual(solution([".#...", "..#..", "...#."]), [0, 1, 3, 4]));
console.log(
  stringEqual(
    solution([
      "..........",
      ".....#....",
      "......##..",
      "...##.....",
      "....#.....",
    ]),
    [1, 3, 5, 8]
  )
);
console.log(
  stringEqual(
    solution([
      ".##...##.",
      "#..#.#..#",
      "#...#...#",
      ".#.....#.",
      "..#...#..",
      "...#.#...",
      "....#....",
    ]),
    [0, 0, 7, 9]
  )
);
console.log(stringEqual(solution(["..", "#."]), [1, 0, 2, 1]));

function stringEqual(obj1, obj2) {
  return obj1.toString() === obj2.toString();
}
