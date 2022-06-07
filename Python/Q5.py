r=[11,14,17,19,14,10,14,10,18,10,19,10,14,15,17,18,14,17,14]
#Method 1
key=list(set(r))
val=[]
for i in r:
    val.append(r.count(i))
d1=dict(zip(key,val))
print(d1)    

#Method 2
from collections import Counter
res=Counter(r)
print(res)