
def solution(priorities, location):
    n=0
    answer=0
    while len(priorities) > 0:
        flag=1
        v=priorities[0]
        for i in range(0,len(priorities)):
           if(v<priorities[i]):
               priorities.append(v)
               del priorities[0]
               flag=0
               break
        if(flag==1):
            if(location==priorities[0]):
                answer=priorities[0]
                break
            del priorities[0]
            n+=1
            
               
    return answer

if __name__=="__main__":
    print(solution([2,1,3,2],2))
    print(solution([1,1,9,1,1,1],0))