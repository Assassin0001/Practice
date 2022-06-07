names=['A','C','D','E','B','C','B','A','C','D','E']
marks=[49,56,78,89,94,90,80,43,54,61,73]

d={}
for i in range(len(names)):
    if names[i] not in d.keys():
        d[names[i]]=marks[i]
    else: d[names[i]]+=marks[i]
print(d)