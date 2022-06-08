# Check if Armstrong number or not.
#Method 1
def armstr(n):
    temp=n
    arm=0
    l=len(str(n))
    while temp>0:
        rem=temp%10
        arm+=rem**l
        temp//=10
    if arm==n:
        print(f'{n} is armstrong number.')
    else:
        print(f'{n} is not armstrong number.')

n= int(input('Enter a no. '))
armstr(n)

#Method 2
n=int(input('Enter a no. '))
n=str(n)
result=0
power=len(n)
for i in n:
    result=result+(int(i)**power)
if int(n)== result:
    print(f'{n} is armstrong number.')
else:
    print(f'{n} is not armstrong number.')    