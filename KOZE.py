import numpy as np
import copy 
n=int(input())
m=int(input())
mirco_backyard=[[]]
if n>=3 and m in range(1,250):
	for i in range(n*m):
		inp=input()
		mirco_backyard.append(inp)
		arra=mirco_backyard[1:]
		
else:
	print()

wolf=0
sheep=0
for i in range(len(arra)):
	if arra[i]=='k':
		wolf+=1
	elif arra[i]=='v':
		sheep+=1


arra=np.reshape(arra,(n,m))
new_arra=copy.deepcopy(arra)
#new_arra=np.zeros(shape=(n,m))
for j in range(0,n):
	if arra[0,j]=='k' or arra[0,j]=='v' or arra[0,j]=='.':
		new_arra[0,j]='red'
		
	if arra[-1,j]=='k' or arra[-1,j]=='v' or arra[-1,j]=='.':
		new_arra[-1,j]='red'

for i in range(0,n):
	if arra[i,0]=='k' or arra[i,0]=='v' or arra[i,0]=='.':
		new_arra[i,0]='red'
	if arra[i,-1]=='k' or arra[i,-1]=='v' or arra[i,-1]=='.':
		new_arra[i,-1]='red'

for i in range(0,n):
    for j in range(0,m):
        #print(i)
        #print()
        try:
            if new_arra[i,j]=='red' and new_arra[i-1,j]=='k'or new_arra[i-1,j]=='v':
                new_arra[i-1,j]='red'
            elif new_arra[i,j]=='red' and new_arra[i+1,j]=='k'or new_arra[i+1,j]=='v':
                new_arra[i+1,j]='red'
            elif new_arra[i,j]=='red' and new_arra[i,j-1]=='k'or new_arra[i,j-1]=='v':
                new_arra[i,j-1]='red'
            elif new_arra[i,j]=='red' and new_arra[i,j+1]=='k'or new_arra[i,j+1]=='v':
                new_arra[i,j+1]='red'
        except:
            jap=0


k_count=0
v_count=0
for i in range(0,n):
	for j in range(0,m):
		if new_arra[i,j]=='k':
			k_count+=1
		if new_arra[i,j]=='v':
			v_count+=1

if v_count>k_count and v_count-k_count<k_count:
	v=v_count-k_count
	try:
		k_count=k_count-v
	except:
		k_count=0
elif v_count<k_count and k_count-v_count<v_count:
	vm=k_count-v_count
	try:
		v_count=v_count-vm
	except:
		v_count=0
elif v_count==k_count:
	k_count=0
else:
	v_count-=1
	
print(v_count)
print(k_count)
