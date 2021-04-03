const dict = {}

function solution(giftCards, wants) {
  let result = 0
  for (const giftCard of giftCards) {
    dict[giftCard] = dict[giftCard] ? dict[giftCard] + 1 : 1
  }
  for (const want of wants) {
    if (dict[want] !== undefined && dict[want] > 0) {
      dict[want]--
    } else {
      result++
    }
  }
  return result
}

console.log(solution([4, 5, 3, 2, 1],	[2, 4, 4, 5, 1]) === 1)
// console.log(solution([5, 4, 5, 4, 5], [1, 2, 3, 5, 4]) === 3)


