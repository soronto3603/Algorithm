function solution(names, scores, array) {
  const dict = {};
  for (const [index, name] of Object.entries(names)) {
    dict[name] = scores[index];
  }

  const result = array.map((v) => {
    let score = 0;
    for (const _v of v) {
      score += dict[_v] ?? 0;
    }
    return score;
  });
  return result;
}

console.log(
  stringEqual(
    solution(
      ["may", "kein", "kain", "radi"],
      [5, 10, 1, 3],
      [
        ["may", "kein", "kain", "radi"],
        ["may", "kein", "brin", "deny"],
        ["kon", "kain", "may", "coni"],
      ]
    ),
    [19, 15, 6]
  )
);
console.log(
  stringEqual(
    solution(
      ["kali", "mari", "don"],
      [11, 1, 55],
      [
        ["kali", "mari", "don"],
        ["pony", "tom", "teddy"],
        ["con", "mona", "don"],
      ]
    ),
    [67, 0, 55]
  )
);
console.log(
  stringEqual(
    solution(
      ["may", "kein", "kain", "radi"],
      [5, 10, 1, 3],
      [["may"], ["kein", "deny", "may"], ["kon", "coni"]]
    ),
    [5, 15, 0]
  )
);

function stringEqual(obj1, obj2) {
  return obj1.toString() === obj2.toString();
}
