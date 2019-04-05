# 1. 주어진 문자열의 리스트에서 처음과 마지막 문자가 같고 문자열의 길이가 2보다 크거나 같은 
#    문자열들을 찾아 개수와 함께 출력하는 프로그램을 작성하시오.

sample = [
    "abcda",
    "sfsdfs",
    "ss",
    "345jer3",
    "345fg"
]

count = 0
for x in sample:
    if( len(x) >= 2 and x[0] == x[len(x)-1] ):
        count+=1
        print(x,len(x))
print( "total : ",count)

# Output
# abcda 5
# sfsdfs 6
# ss 2
# 345jer3 7

# 2. 임의의 중복된 숫자(정수)로 구성된 리스트를 생성하고, 중복된 숫자를 제거한 후, 
#  새로운 리스트에 추가하여 출력하는 프로그램을 작성하시오.

sample = [
    34,56,28,77,19,28,28,34,87,53,105,34
]

answer = []
for x in sample:
    if not x in answer:
        answer.append(x)

print(answer)
# [34, 56, 28, 77, 19, 87, 53, 105]