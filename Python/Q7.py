s=input('Enter a string :')
count=0
vowel='aeiou'
for i in s:
    if i.lower() in vowel:
        count+=1
print(count)