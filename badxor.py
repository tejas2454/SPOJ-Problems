import itertools 
T=int(input())
count=0
A=[]
B=[]
output=[]
while(count<T):
    val=input()
    val=val.split()
    N=int(val[0],10)
    M=int(val[1],10)
    if N in range(0,1001) and M in range(0,1001):
        c=input()
        d=input()
                
        for x in c.split():
            A.append(x)
        subsests_A=[]
        for i in range(len(A)):
            subsests_A.append(findsubsets(A,i))    

        
        for y in d.split():
            B.append(x)
        subsests_B=[]
        for i in range(len(B)):
            subsests_B.append(findsubsets(B,i))
        count1=0
        for g in subsests_A:
            if g in subsests_B:
                count1+=1

        for i in range(T):
            p1="Case:"
            output.append(p1)
            output.append(T)
            output.append(count1)
            
        count+=1

            
        



    