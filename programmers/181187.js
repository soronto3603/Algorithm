function toDistance(point1, point2) {
  return Math.sqrt(
    Math.pow(point1.x - point2.x, 2) + Math.pow(point1.y - point2.y, 2)
  );
}

function solution(a, b) {
  let answer = 0;
  const center = {
    x: 0,
    y: 0,
  };
  for (const x of [...new Array(b + 1 + b).keys()].map((v) => v - b)) {
    for (const y of [...new Array(b + 1 + b).keys()].map((v) => v - b)) {
      const point = {
        x,
        y,
      };

      const distance = toDistance(center, point);

      if (distance <= b && distance >= a) {
        answer += 1;
      }
    }
  }

  return answer;
}

console.log(solution(2, 3));
