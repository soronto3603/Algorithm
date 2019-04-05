# 크로아티아 알파벳
# https://www.acmicpc.net/problem/2941

string=input()

croa_r = ["c=","dz=","d-","lj","nj","s=","z="]

croa = ["c=","dz","d-","lj","nj","s=","z="]

result=0
i=0
while(True):

    if(i+2 > len(string)):
        result+=1
        break
    sub_s=string[i:i+2]
    # print(sub_s)
    if(sub_s in croa):
        
        if(sub_s == "dz"):
            i+=2
        result+=1

        i+=2
        # print("true",result)
    else:
        
        result+=1
        i+=1
        # print("false",result)
print(result)

# ljes=njak
# ddz=z=
# nljj
# c=c=