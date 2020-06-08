function compareDate(d1, d2) {
  if (d1 === d2) {
    return 0
  }

  const [m1, day1] = d1.split('/')
  const [m2, day2] = d2.split('/')
  if (m1 > m2) {
    return 1
  } else if (m1 < m2) {
    return -1
  }

  if (day1 > day2) {
    return 1
  } else {
    return -1
  }
}

function solution(offers) {
  const q = offers.reverse()
  let select = null
  while(q.length !== 0) {
    console.log(select)
    if (!select) {
      select = q.pop()
      continue
    }

    const [select_s, select_end, select_money] = select.split(' ')
    const [target_s, target_end, target_money] = q.pop().split(' ')
    // 선택된 오퍼의 끝일보다 다음오퍼의 시작일이 높으면
    if(compareDate(select_end, target_s) === -1) {
      break
    }

    if (+select_money < +target_money) {
      select = [target_s, target_end, target_money].join(' ')
      continue
    } else if (+select_money === +target_money) {
      if(compareDate(select_end, target_end) === -1) {
        select = [target_s, target_end, target_money].join(' ')
      }
    }
    continue
  }
  return +select.split(' ')[2]
}

let result
result = solution(["10/05 10/12 2400", "10/05 10/10 2500", "10/07 10/15 2300", "10/08 10/30 3000", "10/15 11/03 3000", "10/20 11/01 3500", "11/02 11/11 4000"])
console.log(result === 3500)
result = solution(["07/01 07/30 2000", "07/01 07/15 2000", "07/01 07/30 2000", "07/01 07/30 1500", "07/05 07/30 2100", "07/20 08/01 2400", "07/20 07/31 2400", "07/31 09/01 2900", "08/01 08/15 3000", "08/14 08/19 2000","08/17 08/30 4000"])
console.log(result === 3000)