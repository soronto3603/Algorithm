function solution(map, operations) {
  const current = {
    x: 0,
    y: 0,
  };

  for (const row of Object.keys(map)) {
    for (const col of Object.keys(map[row])) {
      if (map[row][col] === "S") {
        current.x = +col;
        current.y = +row;
      }
    }
  }

  const q = operations;

  function checkOutOfBound(point) {
    const { x, y } = point;
    if (x < 0 || y < 0) return true;

    if (x >= map[0].length || y >= map.length) {
      return true;
    }
    return false;
  }

  function checkObstacle(point, operation) {
    const [direction, distance] = operation.split(" ");
    const next = { ...point };

    for (const step of [...Array(+distance).keys()].map((v) => v + 1)) {
      switch (direction) {
        case "E":
          next.x += 1;
          break;
        case "W":
          next.x -= 1;
          break;
        case "S":
          next.y += 1;
          break;
        case "N":
          next.y -= 1;
          break;
      }

      if (map[next.y][next.x] === "X") {
        return true;
      }
    }

    return false;
  }

  function getNextPoint(point, operation) {
    const [direction, distance] = operation.split(" ");
    const next = { ...point };
    switch (direction) {
      case "E":
        next.x += +distance;
        break;
      case "W":
        next.x -= +distance;
        break;
      case "S":
        next.y += +distance;
        break;
      case "N":
        next.y -= +distance;
        break;
    }

    return next;
  }

  while (q.length > 0) {
    const operation = operations.shift();

    const next = getNextPoint(current, operation);

    if (checkOutOfBound(next)) {
      continue;
    }

    if (checkObstacle(current, operation)) {
      continue;
    }

    current.x = next.x;
    current.y = next.y;
  }

  return [current.y, current.x];
}

console.log(
  stringEqual(solution(["SOO", "OOO", "OOO"], ["E 2", "S 2", "W 1"]), [2, 1])
);
console.log(
  stringEqual(solution(["SOO", "OXX", "OOO"], ["E 2", "S 2", "W 1"]), [0, 1])
);
console.log(
  stringEqual(
    solution(["OSO", "OOO", "OXO", "OOO"], ["E 2", "S 3", "W 1"]),
    [0, 0]
  )
);

function stringEqual(obj1, obj2) {
  return obj1.toString() === obj2.toString();
}
