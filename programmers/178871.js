function solution(players, callings) {
  const dict = {};
  const reverse = {};
  for (const player of players) {
    const index = players.indexOf(player);
    dict[player] = index;

    reverse[index] = player;
  }

  function swap(player1, player2) {
    dict[player1] = dict[player1] - 1;
    dict[player2] = dict[player2] + 1;

    reverse[dict[player1]] = player1;
    reverse[dict[player2]] = player2;
  }

  for (const calling of callings) {
    const player1 = calling;
    const player2 = reverse[dict[player1] - 1];

    swap(player1, player2);
  }

  const entries = Object.entries(dict);
  entries.sort((a, b) => a[1] - b[1]);

  return entries.map((v) => v[0]);
}

const result = stringEqual(
  solution(
    ["mumu", "soe", "poe", "kai", "mine"],
    ["kai", "kai", "mine", "mine"]
  ),
  ["mumu", "kai", "mine", "soe", "poe"]
);

function stringEqual(obj1, obj2) {
  return obj1.toString() === obj2.toString();
}
