def medianFunction(lst):
    lst.sort()
    #print(lst)
    if len(lst)%2==0:
            if lst[int(len(lst)/2)] < lst[int(len(lst)/2 + 1)]:
                print(lst[int(len(lst)/2)-1])
                lst.pop(int(len(lst)/2)-1)
            else:
                print(lst[int((len(lst)/2)+1)-1])
                lst.pop(int((len(lst)/2)+1)-1)
    else:
        print(lst[int(len(lst)/2)+1-1])
        lst.pop(int(len(lst)/2)+1-1)
    #print(int(len(lst)/2)+1)
    #print(lst)

numTestCase = input ("")
#print(numTestCase)  
tempTestCase=int(numTestCase)

lst=[]

#print(tempTestCase)

while tempTestCase > 0:
    inputNo=input("")

    #print(lst)
   
    if int(inputNo) == 0:
        lst.clear()
        tempTestCase=tempTestCase-1
       
    if int(inputNo) == -1 and len(lst)>0:
        medianFunction(lst)
    elif int(inputNo) != 0 :
        lst.append(int(inputNo))